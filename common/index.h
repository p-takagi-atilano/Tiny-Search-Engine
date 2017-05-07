/* 
 * index.h - header file for CS50 'index module'
 *
 * Contains methods to save and load index from file
 * and some testing methods
 *
 * Paolo Takagi-Atilano, May 2017
 */

#ifndef __INDEX_H
#define __INDEX_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "hashtable.h"

/***********************************************************************/

/* given an index, will save to given filename
 * returns true if ran succesfully, false if errors
 */
bool index_save(const char *filename, struct hashtable *index);

/* makes a writeable file given index filename
 * returns false if failed, true if success
 */
bool test_index_filename(const char *index_filename);

/* given an index and a filename, will add all indices in file to index
 * data structure.  Returns true of success, false if errors
 */
bool index_load(const char *filename, struct hashtable *index);

#endif // __INDEX_H
