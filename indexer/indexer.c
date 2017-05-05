/* 
 * indexer.c - the indexer module reads documents in the pageDirectory output
 * from the crawler module.  It then builds an inverted index mapping from
 * words to documents, and writes that index to a file. The querier module will
 * read the index and use it to answer queries.
 *
 * ./indexer pageDirectory indexFilename
 *
 * Paolo Takagi-Atilano, May 2017
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "hashtable.h"
#include "counters.h"
#include "webpage.h"
#include "index.h"
#include "pagedir.h"
#include "word.h"
#include "file.h"

/* Function prototypes */
void validate_parameters(const int argc, const char *argv[]);
void index_build(const char *directory, struct hashtable *index);
static void clean_counters(void *item);

/* main */
int main (const int argc, const char *argv[])
{
  validate_parameters(argc, argv);

  int num_slots = 400;
  struct hashtable *index = hashtable_new(num_slots);
  if (index == NULL) {
	fprintf(stderr, "hashtable_new failed\n");
	exit(4);
  }

  fprintf(stdout, "indexing from: %s to: %s\n", argv[1], argv[2]);

  index_build(argv[1], index);
  index_save(argv[2], index); 

  // clean up:
  hashtable_delete(index, clean_counters);
  
}

// validates arguments given to program
void validate_parameters(const int argc, const char *argv[])
{
  if (argc != 3) {
    fprintf(stderr, "usage: %s pageDirectory indexFilename\n", argv[0]);
    exit(1);
  } else if (!is_crawled(argv[1])) {
    fprintf(stderr, "pageDirectory %s is not valid\n", argv[1]);
    exit(2);
  } else if (!test_index_filename(argv[2])) {
	fprintf(stderr, "indexFilename %s is not valid", argv[2]);
	exit(3);
  }
}

// builds an inverse index given crawler directory and the index data structure
// (it is passed an empty index)
void index_build(const char *directory, struct hashtable *index)
{
  int id = 1;
  char idx[sizeof(int)];
  sprintf(idx, "%d", id);
  struct webpage *page  = load_page(directory, idx);
  
  while (page != NULL) { // iterates thorough all the pages
	int pos = 0;
	char *word;

	// iterates through words in a page
	while ((pos = webpage_getNextWord(page, pos, &word)) > 0) {
	  if (strlen(word) > 2) {
		normalize_word(word);
	    struct counters *cp = hashtable_find(index, word);
	    if (cp == NULL) {  // doesn't yet exist
		  cp = counters_new();
		  if (cp != NULL) {
		    hashtable_insert(index, word, cp);
		  } else {
			fprintf(stdout, "counters_new failed");
		  }
	    }
	    counters_add(cp, id);
	  }
	  free(word);
	}
	id++;
	sprintf(idx, "%d", id);
	
	webpage_delete(page);
	page = load_page(directory, idx);
  }
}

// method used to delete counters objects
static void clean_counters(void *item)
{
  struct counters *ctrs = item;
  counters_delete(ctrs);
}
