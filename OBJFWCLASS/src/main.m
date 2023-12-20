#import "File/File.h"

int help(const char *);
int start(const char **);

int
main(int argc, const char ** argv)
{
	return (argc < 2) ? help(*argv) : start(argv);
}

int
help(const char * pn)
{
	fprintf(stderr,
		"USAGE:\n%s [filename]\n",
		pn);

	return 1;
}

int
start(const char ** argv)
{
	File * myFile;

	/*
	 * Open all the files passed
	 */
	while (*++argv) {
		myFile = [[File alloc] init];

		if ([myFile open:*argv:'r'] < 0)
			return 1;

		fprintf(stdout,
			"File - %s\nSize - %lu Bytes\n",
			*argv, [myFile getsize]);

		if ([myFile close])
			return 1;
	}

	return 0;
}
