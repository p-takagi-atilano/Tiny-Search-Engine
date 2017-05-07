/*
 * index.c - CS50 'index' module
 *
 * see index.h for more information.
 *
 * Paolo Takagi-Atilano, April 2017
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "index.h"
#include "counters.h"
#include "hashtable.h"
#include "file.h"

static void print_counts(void *arg, const int key, int count);
static void print_words(void *arg, const char *key, void *item);

bool index_load(const char *filename, struct hashtable *index)
{
  if (filename == NULL || index == NULL) {
	return false;
  }

  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
	return false;
  }

  int lines = lines_in_file(fp);
  for (int i = 0; i < lines; i++) {
	char word[100];
	fscanf(fp, " %s ", word);

	struct counters *ctrs = counters_new();

	int key;
	int count;
	while (fscanf(fp, "%d %d ", &key, &count) == 2) {
	  counters_set(ctrs, key, count);
	}
	hashtable_insert(index, word, ctrs);
  }
  fclose(fp);
  return true;
}

bool index_save(const char *filename, struct hashtable *index)
{ 
  if (filename == NULL || index == NULL) {
    return false;
  }
  
  FILE *fp = fopen(filename, "w");
  if (fp == NULL) {
    return false;
  }
  
  hashtable_iterate(index, fp, print_words);
  
  fclose(fp);
  return true;
}

static void print_words(void *arg, const char *key, void *item)
{
  FILE *fp = arg;
  struct counters *ctrs = item;
  if (fp != NULL && ctrs != NULL) {
	fprintf(fp, "%s ", key);
	counters_iterate(ctrs, fp, print_counts);
	fprintf(fp, "\n");
  }
}

static void print_counts(void *arg, const int key, int count)
{
  FILE *fp = arg;
  if (fp != NULL) {
    fprintf(fp, "%d %d ", key, count);
  }
}

bool test_index_filename(const char *index_filename)
{
  if (index_filename == NULL) {
    return false;
  }
  FILE *fp = fopen(index_filename, "w");
  if (fp == NULL) {
    return false;
  }
  fclose(fp);
  return true;
}


