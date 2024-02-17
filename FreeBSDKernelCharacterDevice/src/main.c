#include <sys/types.h>
#include <sys/systm.h>
#include <sys/param.h>
#include <sys/module.h>
#include <sys/kernel.h>
#include <sys/conf.h>
#include <sys/uio.h>
#include <sys/errno.h>
#include <sys/malloc.h>

/* TCD (test character device) */

#define TCD_BUFFER_SIZE 255

/* Function prototypes */
static d_open_t  tcd_open;
static d_close_t tcd_close;
static d_read_t  tcd_read;
static d_write_t tcd_write;

/* Character device entry points */
static struct cdevsw tcd_cdevsw = {
	.d_version = D_VERSION,
	.d_open    = tcd_open,
	.d_close   = tcd_close,
	.d_read    = tcd_read,
	.d_write   = tcd_write,
	.d_name    = "tcd",
};

/* Whats stored on our device */
struct tcd_device_data {
	int len;
	char string[TCD_BUFFER_SIZE + 1];
};

/* Variables */
static struct cdev            *tcd_dev;
static struct tcd_device_data *tcd_data;

MALLOC_DECLARE(TCD_BUFFER);
MALLOC_DEFINE(TCD_BUFFER, "TCD_BUFFER", "buffer for test character device");

/*
 * Handles the load & unload events
 */
static int
tcd_loader(struct module *mod __unused, int what, void *arg __unused)
{
	int ret = 0;

	switch (what) {
	case MOD_LOAD: /* kldload -v *.ko */
		ret = make_dev_p(MAKEDEV_CHECKNAME | MAKEDEV_WAITOK,
				&tcd_dev,
				&tcd_cdevsw,
				0,
				UID_ROOT,
				GID_WHEEL,
				0600,      /* Permissions */
				"tcd");   /* The name of the device in /dev/ */

		if (ret != 0)
			break;

		tcd_data = malloc(sizeof(*tcd_data), TCD_BUFFER, M_WAITOK | M_ZERO);
		uprintf("tcd : successfully loaded\n");
		break;
	case MOD_UNLOAD: /* kldunload -v *.ko */
		destroy_dev(tcd_dev);
		free(tcd_data, TCD_BUFFER);
		uprintf("tcd : successfully (un)loaded\n");
		break;
	default:
		ret = EOPNOTSUPP;
		break;
	}

	return (ret);
}

static int
tcd_open(struct cdev *dev __unused, int oflags __unused, int devtype __unused,
		struct thread *td __unused)
{
	int ret = 0;
	uprintf("tcd : successfully opened\n");
	return (ret);
}

static int
tcd_close(struct cdev *dev __unused, int fflag __unused, int devtype __unused,
		struct thread *td)
{
	int ret = 0;
	uprintf("tcd : successfully closed\n");
	return (ret);
}

static int
tcd_read(struct cdev *dev __unused, struct uio *uio, int ioflag __unused)
{
	size_t amt;
	int ret = 0;

	amt = MIN(uio->uio_resid, (uio->uio_offset >= tcd_data->len + 1) ? 0 :
			tcd_data->len + 1 - uio->uio_offset);

	if ((ret = uiomove(tcd_data->string, amt, uio)) != 0)
		uprintf("tcd : uiomove failed");

	return (ret);
}

static int
tcd_write(struct cdev *dev __unused, struct uio *uio, int ioflag __unused)
{
	size_t amt;
	int ret = 0;

	/* Either write or append, do not allow random access */
	if (uio->uio_offset != 0 && (uio->uio_offset != tcd_data->len))
		return (EINVAL);

	/* New message ? if so reset the size */
	if (uio->uio_offset == 0)
		tcd_data->len = 0;

	/* Copy string from user memory to kernel memory */
	amt = MIN(uio->uio_resid, (TCD_BUFFER_SIZE - tcd_data->len));

	ret = uiomove(tcd_data->string + uio->uio_offset, amt, uio);

	/* Now null terminate string */
	tcd_data->len = uio->uio_offset;
	tcd_data->string[tcd_data->len + 1] = 0;

	if (ret != 0)
		uprintf("tcd : write failed, bad address\n");

	return (ret);
}

/* Declare the module */
DEV_MODULE(tcd, tcd_loader, NULL); 
