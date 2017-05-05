/* 
 * word.h - header file for CS50 'word' module
 *
 * Contains methods to manipulate words
 *
 * Paolo Takagi-Atilano
 */
#ifndef __WORD_H
#define __WORD_H

#include <stdio.h>
#include <stdlib.h>

/***********************************************************************/

/* 
 * given a word in string format (a word is a group of letters), make each
 * word lowercase
 */
void normalize_word(char *word);

#endif // __WORD_H
