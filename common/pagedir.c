/*
 * pagedir.c - CS50 'pagedir' module
 *
 * see pagedir.h for more information.
 *
 * Paolo Takagi-Atilano, April 2017
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "pagedir.h"


/**************** test_dir() ****************/
bool test_dir (char *dirname) {
  char *file = "/.crawler";
  char filename[sizeof(dirname) + sizeof(file)];
  strcpy(filename, dirname);
  strcat(filename, file);

  FILE *fp = fopen(filename, "w");
  if (fp != NULL) {
	fclose(fp);
	return true;
  }
  return false;
}
