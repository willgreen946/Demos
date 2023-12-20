#ifndef __SYSTEM_H__
#define __SYSTEM_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * This file contains declerations for system code
 */

/* Returns dmesg output */
char * get_KernelMessages(void);

/* Returns CPU cores */
int get_ProcessorCores(void);

#endif /* __SYSTEM_H__ */
