/* 
 * indextest.c - the indextest module tests the saving and loading capabilities
 * of the indexer.c
 *
 * ./indextest oldIndexFilename newIndexFilename
 *
 * Paolo Takagi-Atilano, May 2017
 */

#include <stdio.h>
#include <stdbool.h>
#include "hashtable.h"
#include "index.h"
#include "counters.h"

/* Function prototypes */
static void clean_counters(void *item);

/* main */
int main (const int argc, const char *argv[])
{
  // validating parameters;
  if (argc != 3) {
    fprintf(stderr, "usage: %s oldIndexFilename newIndexFilename\n", argv[0]);
    exit(1);
  }

  // getting started:
  int num_slots = 400;
  struct hashtable *index = hashtable_new(num_slots);
  
  // trying index_load and then index_save
  if (index_load(argv[1], index)) {
	fprintf(stdout, "index_load succeeded\n");
	if (!index_save(argv[2], index)) {
	  fprintf(stderr, "index_save failed\n");
	  exit(3);
	}
	fprintf(stdout, "index_save succeeded\n");
  } else {
	fprintf(stderr, "index_load failedn\n");
	exit(2);
  }

  // clean up:
  hashtable_delete(index, clean_counters);
}

static void clean_counters(void *item)
{
  struct counters *ctrs = item;
  counters_delete(ctrs);
}
