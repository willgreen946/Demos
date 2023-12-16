#import <Foundation/Foundation.h>

int help(const char *);
int openfiles(const char **);
NSString * readfile(NSString *);
int writefile(NSString *, NSString *);

int
main(int argc, const char ** argv)
{
	@autoreleasepool {
		return (argc < 2) ? help(*argv) : openfiles(argv);
	}
}

int
help(const char * pn)
{
	NSLog(@"%s usage:\n[filename]\n",
				pn);
	return 1;
}

int
openfiles(const char ** argv)
{
	BOOL exists;
	NSString * path;
	NSFileManager * fm;
	NSString * contents;

	fm = [NSFileManager defaultManager];

	/*
	 * Open all files in argv
	 */
	while (*++argv) {
		path = [NSString stringWithFormat:@"%s", *argv];

		if (!(exists = [fm fileExistsAtPath:path])) {
			NSLog(@"File \"%s\" does not exist\n", *argv);
			return 1;
		}

		/* Read from the file */
		if ((contents = readfile(path)))
			fprintf(stdout, "%s", [contents UTF8String]);

		/* Write a string to the file */
		if (writefile(path, @"Hello, Objective-C\n"))
			return 1;
	}

	return 0;
}


NSString *
readfile(NSString * path)
{
	NSString * contents;

	if (!path)
		return nil;

	contents = [NSString stringWithContentsOfFile:path
																			 encoding:NSUTF8StringEncoding
																					error:nil];
	return contents;
}

int
writefile(NSString * path, NSString * str)
{
	if (!path || !str)
		return 1;

	[str writeToFile:path
				atomically:YES
					encoding:NSUTF8StringEncoding
						 error:nil];

	return 0;
}
