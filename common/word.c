/*
 * word.c - CS50 'word' module
 *
 * see word.h for more information
 *
 * Paolo Takagi-Atilano, April 2017
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void normalize_word(char *word)
{
  if (word != NULL) {
    for (int i = 0; word[i]; i++) {
      word[i] = tolower(word[i]);
    }
  }
}
