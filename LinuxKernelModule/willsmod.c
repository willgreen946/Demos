#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>

#define ID "[MYMODULE]"

/* Meta Data of the module*/
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Will Green");
MODULE_DESCRIPTION("A Simple Test Linux Kernel Module");

static int __init init(void);
static void __exit cleanup(void);

/*
 * module main()
 */
static int __init init(void)
{
	int retval;

	printk("%s : Module Was Loaded\n", ID);

	/*
	 * Register device nr
	 */
	return 0;
}

/*
 * Unloads the module
 */
static void __exit cleanup(void)
{
	printk("%s : My Module Was UnLoaded\n"
		ID);
}

module_init(init);
module_exit(cleanup);
