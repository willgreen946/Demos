#import <stdio.h>
#import <errno.h>
#import <fcntl.h>
#import <string.h>
#import <unistd.h>
#import <ObjFW/OFObject.h>
#import "File.h"

@implementation File
	/*
	 * Check that a file exists
	 */
	- (unsigned int) exists:(const char *) fn
	{
		if (access(fn, F_OK) < 0) {
			fprintf(stderr,
				"%s : %s : %s\n",
				fn, strerror(errno), __func__);
			return 0;
		}

		return 1;
	}

	/*
	 * Deletes the file
	 */ 
	- (signed int) delete
	{
		if (unlink(fname) < 0) {
			fprintf(stderr,
				"%s : %s : %s\n",
				fname, strerror(errno), __func__);
			return -1;
		}

		[super dealloc];

		return 0;
	}

	/*
	 * Returns the size of the file
	 */
	- (unsigned long) getsize
	{
		signed long size = 0L;

		if ((size =
			(signed long) lseek(fdescriptor, 0, SEEK_END)) < 0) {
			fprintf(stderr, "%s : %s : %s\n",
				fname, strerror(errno), __func__);
			return 0;
		}

		/* Reset position to the start */
		if (lseek(fdescriptor, 0, SEEK_SET) < 0) {
			fprintf(stderr, "%s : %s : %s\n",
				fname, strerror(errno), __func__);
			return 0;
		}

		return (unsigned long) size;
	}

	/*
	 * Retrieve a line from the file
	 */
	- (char *) getline:(unsigned long) index
	{
		char * line = (char *) 0;

		return line;
	}

	/*
	 * Open a file
	 */
	- (signed int) open:(const char *) fn :
			(const char) mode
	{
		fname = fn;

		switch (mode) {
		case 'r':
			fmode = O_RDONLY;
			break;
		case 'w':
			fmode = O_RDWR | O_CREAT;
			break;
		case 'a':
			fmode = O_APPEND | O_CREAT;
			break;
		default:
			fprintf(stderr,
				"%s : No such mode %c : %s\n",
				fname, mode, __func__); 
			return -1;
		}

		if ((fdescriptor =
			open(fname, fmode)) < 0) {
			fprintf(stderr,
				"%s : %s : %s\n",
				fname, strerror(errno), __func__);
			return -1;
		}

		fsize = [self getsize];

		return fdescriptor;
	}

	/*
	 * Close a file and frees memory
	 */
	- (signed int) close
	{
		signed int rval;

		if ((rval = close(fdescriptor)) < 0) {
			fprintf(stderr,
				"%s : %s : %s\n",
				fname, strerror(errno), __func__);
			return -1;
		}

		[super dealloc];

		return rval;
	}
@end
