#ifndef __FILE_FILE_H__
#define __FILE_FILE_H__

#import <stdio.h>
#import <errno.h>
#import <fcntl.h>
#import <string.h>
#import <unistd.h>
#import <ObjFW/OFObject.h>

@interface File : OFObject
{
@private
	int fmode;
	const char * fname;
	unsigned long fsize;
	signed int fdescriptor;
}
	/*
	 * Checks that a file exists
	 */
	- (unsigned int) exists:(const char *) fn;

	/*
	 * Deletes the file
	 */
	- (signed int) delete;

	/*
	 * Returns the size of the file
	 */
	- (unsigned long) getsize;

	/*
	 * Retrieve a line from the file
	 */
	- (char *) getline:(unsigned long) index;

	/*
	 * Opens the file
	 */
	- (signed int) open:(const char *) fn :
			(const char) mode;

	/*
	 * Closes the file
	 */
	- (signed int) close;
@end

#endif /* __FILE_FILE_H__ */
