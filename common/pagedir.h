/*
 * pagedir.h - header file for CS50 'pagedir' module
 *
 * This contains the testdir method, part of common.a library
 *
 * Paolo Takagi-Atilano, April 2017
 *
 */

#ifndef __PAGEDIR_H
#define __PAGEDIR_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/***********************************************************************/


/* Given a directory name as a strig, will test to see this directory exists,
 * and is writable.  If it not, test_dir returns false.
 * If it is, then test_dir will create a file called .crawler in the directory,
 * and will return true
 */
bool test_dir (char *dirname);





#endif // __PAGEDIR_H
