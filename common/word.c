/*
 * word.c - CS50 'word' module
 *
 * see word.h for more information
 *
 * Paolo Takagi-Atilano, April 2017
 */ 

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void normalize_word(char *word)
{
  if (word != NULL) {
    for (int i = 0; word[i]; i++) {
      word[i] = tolower(word[i]);
    }
  }
}

char is_words(char *word)
{
  if (word != NULL) {
	int len = strlen(word);
	for (int i = 0; i<len; i++) {
	  char c = word[i];
	  if (!isalpha(c) && !isspace(c)) {
		return c;
	  }
	}
  }
  return 'a';
}
