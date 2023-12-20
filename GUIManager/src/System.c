#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#include "System.h"

char *
get_KernelMessages(void)
{
	size_t fs = 0;
	FILE * fp = (FILE *) 0;
	char * buf = (char *) 0;

	if (!(fp = fopen("/var/log/messages", "r")))
		return (char *) 0;

	/* Get size of file */
	fseek(fp, 0L, SEEK_END);
	fs = ftell(fp);
	fseek(fp, 0L, SEEK_SET);

	if (!(buf = (char *) malloc(fs)))
		return buf;

	fread(buf, fs, fs, fp);	

	if (fp)
		fclose(fp);

	return buf;
}

int
get_ProcessorCores(void)
{
	int count = 0;

	count = sysconf(_SC_NPROCESSORS_ONLN);

	return count;
}
