/* 
 * querier.c - 'querier' module for TinySearch Engine
 *
 * ./querier pageDirectory indexFilename
 *
 * Paolo Takagi-Atilano, May 2017
 */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "file.h"
#include "webpage.h"
#include "index.h"
#include "hashtable.h"
#include "counters.h"
#include "pagedir.h"
#include "word.h"

/* Structs */
struct two_counters {
  struct counters *c1;
  struct counters *c2;
};

struct counters_node {
  int key;
  int count;
};

/* Function prototypes */
static void validate_parameters(int argc, char *argv[]);
static bool validate_index_filename (const char *filename);
static void input_query(char *page_directory, struct hashtable *index);
static int tokenize (char *line, char **words);
static bool validate_query(char ** words, int count);
static void build_query (char **words, char *page_directory, struct hashtable *index);
static void sort_query (struct counters *query, char *page_directory);
static int qsort_helper (const void *a, const void *b);
static void nodes_add (void *arg, const int key, int count);
static void and_merge (struct counters *ctrs1, struct counters *ctrs2);
static void and_iterate (void *arg, int key, int count);
static void or_merge (struct counters *ctrs1, struct counters *ctrs2);
static void or_iterate (void *arg, int key, int count);
static void total_counters (void *arg, int key, int count);
static void clean_counters(void *item);


/* main */
int main (int argc, char *argv[])
{
  validate_parameters(argc, argv);

  char *page_directory = argv[1];
  //char *index_filename = argv[2];

  // load index (uses a load factor of .75):
  FILE *temp = fopen(argv[2], "r");
  const int num_slots = (lines_in_file(temp)*4)/3;
  fclose(temp);
  struct hashtable *index = hashtable_new(num_slots);

  if (index == NULL) {
    fprintf(stderr, "hashtable_new failed\n");
    exit(4);
  } else if (!index_load(argv[2], index)) {
    fprintf(stderr, "index_load failed\n");
    exit(5);
  }
  
  // runs it
  input_query(page_directory, index);

  // clean up
  hashtable_delete(index, clean_counters);
}

// takes input from user, until control d is pressed
static void input_query (char *page_directory, struct hashtable *index)
{
  char *line = NULL;
  printf("KEY WORDs:> ");

  // accepting user input
  while((line = readlinep(stdin)) != NULL) {
	char c = is_words(line);
	if (!isalpha(c)) {
      printf("Error: bad character '%c' in query.\n", c);
	  printf("KEY WORDs:> ");
	  continue; // dont do anything more, more onto next one
    }
	int len = 0;
	len = strlen(line);

	// handling empty input
	if (len == 0) {
	  free(line);
	  line = NULL;
	  printf("KEY WORDs:> ");
	  continue;
	}

	// input seems to be valid
	// allocating words to be length of input query
	// there is enough memory for each character to have its own word
	char **words = calloc(len, sizeof(char*));
	if (words == NULL) {
	  fprintf(stderr, "failed to allocate space for 'words'\n");
	  free(line);
	  line = NULL;
	  exit(6); // can't make space for words, no use continuing
	}

	int count = tokenize(line, words);
	if (count == 0) { // if the line is only whitespace
	  if (line){
		free(line);
	  }
	  for (int i = 0; i < count; i++) {
		if (words[i]) {
		  free(words[i]);
		}
	  }
	  if (words) {
		free(words);
	  }
	  line = NULL;
	  printf("KEY WORDs:> ");
	  continue; // don't try anything further is the line is just whitespace
	}

	if (validate_query(words, count)) { // query is valid, so start running it
	  build_query(words, page_directory, index);
	}

	if (line) { // free the line
	  free(line);
	}
 
    // cleaning up all of words:
	for (int i = 0; i < count; i++) {
	  if (words[i]) {
		free(words[i]);
	  }
	}
	if (words) {
	  free(words);
	}
	line = NULL;
	printf("KEY WORDs:> ");
  }
  printf("\n");
}

// from char *line input, create char ** words array of all the words
static int tokenize (char *line, char **words)
{
  char *delim = " \t\r\n\v\f"; // whitespace characters
  int i = 0;

  char *token = strtok(line, delim); // first token
  while (token != NULL) {
	char *temp = malloc(strlen(token)+1);
	strcpy(temp, token);
	normalize_word(temp);
	words[i] = temp;
	i++;
	token = strtok(NULL, delim);
  }

  return i;
}

// if all works out creates a single counters objct that will be results
static void
build_query (char **words, char *page_directory, struct hashtable *index)
{
  printf("Query: ");
  for (int i = 0; words[i] != NULL; i++) {
	printf("%s ", words[i]);
  }
  printf("\n");

  // inspired from BNF
  struct counters *ands = NULL; // andsequences
  struct counters *ors = NULL;  // queries

  for (int i = 0; words[i] != '\0'; i++) {
	if (strcmp(words[i], "and") == 0) {	// ignore if 'and'
	  continue;
	}

	// if this is the first word, or previous word is "or"
	// also must be able to find the word in hashtable
	// make a new andsequence
	char *temp_word = words[i];
	if (i == 0 || (i>1 && strcmp(words[i-1], "or") == 0 
			&& hashtable_find(index, temp_word) != NULL)) {
		ands = counters_new();
		if (ands == NULL) {
		  return;
		}
		or_merge(hashtable_find(index, temp_word), ands);
	}

	// current word is an or
	if (strcmp(words[i], "or") == 0) {
	  if (ors != NULL) { // if no ors has info
		if (ands != NULL) { // if ands has info
		  or_merge(ands, ors); // merge them
		}
	  } else { // ors has no info
		if (ands != NULL) { // ands has no info
		  ors = counters_new(); // make new ors
		  if (ors == NULL) {
            return;
          }
		  or_merge(ands, ors); // merge them
		}
	  }
	  if (ands) { // nothing important in ands, has to be reused-free the space
		counters_delete(ands);
		ands = NULL;
	  }
	  continue; // next iteration
	}

    if (hashtable_find(index, words[i]) != NULL) { // can find word in index
      if (ands != NULL) { // if ands has info, intersect them
        and_merge(hashtable_find(index, words[i]), ands);
      }
	} else { // cannot find word in index
      if (ands != NULL) { // delete ands if necesary, available for next round
        counters_delete(ands);
        ands = NULL;
      }	  
	}
  } // end of iteration

  if (ors != NULL) { // info in ors
	if (ands == NULL) { // no info in ands, so make one
	  ands = counters_new(); 
	  if (ands == NULL) {
		return;
	  }
	}
	or_merge(ors, ands); // merge them, so ands has everything now
  }
  sort_query(ands, page_directory); // sort

  // clean up
  if (ands) {
	counters_delete(ands);
  }
  if (ors) {
	counters_delete(ors);
  }
  //return;
}

static void sort_query (struct counters *query, char *page_directory)
{
  int count = 0; // don't want to print out no matches
  counters_iterate(query, &count, total_counters);
  if (count == 0) {
	printf("No documents match.\n");
	return;
  }
  
  // have some results, so print them out make a counters_node array
  struct counters_node **nodes = calloc(sizeof(struct counters_node), count);
  if (nodes == NULL) {
	fprintf(stderr, "error allocating memory for nodes\n");
	return;
  }

  // initialize every node to null in array
  for (int i = 0; i < count; i++) {
	nodes[i] = NULL;
  }

  counters_iterate(query, nodes, nodes_add);

  int j = 0;
  for (int i = 0; i < count; i++) {
	if (nodes[i]->count > 0) {
	  j++;
	}
  }
  if (j == 0) {  // not redundant
    printf("No documents match.\n");
  } else {
	printf("Matches %d documents (ranked):\n", j);
	qsort(nodes, count, sizeof(struct counters_node *), qsort_helper);

	for (int i = 0; i < count; i++) {
	  struct counters_node *temp_node = nodes[i];
	  char *filename = malloc(strlen(page_directory)+15);
	  sprintf(filename, "%s/%d", page_directory, temp_node->key);
	  FILE *fp = fopen(filename, "r");
 	  if (fp == NULL) { // file doesn't exist
		// should not happen, but just in case to know the issue:
		printf("Could not open file %s\n", filename);
		free(filename);
		fclose(fp);
		continue;
	  } else {
		char *url = NULL;
		url = readlinep(fp); // read url of crawler file
		if (temp_node->count > 0) {
		  printf("score %3d docID %5d : %s\n", temp_node->count, temp_node->key, url);
		} // clean up:
		fclose(fp);
		free(url);
		free(filename);
		continue;
		}
	  }
	  printf("-----------------------------------------------\n");
	}  // clean up each pointer in nodes
	for (int i = 0; i < count; i++) {
	  if (nodes[i]) {
		free(nodes[i]);
	  }
	} // clean up nodes
	if (nodes) {
	  free(nodes);
	}
  }

// function qsort uses to compare counters_nodes
static int qsort_helper (const void *a, const void *b)
{
  struct counters_node **node_a = (struct counters_node**)a;
  struct counters_node **node_b = (struct counters_node**)b;
  // descending order:
  return ((*node_b)->count - (*node_a)->count);
}

// add a node
static void nodes_add (void *arg, const int key, int count)
{
  struct counters_node **nodes = arg;
  struct counters_node *node = malloc(sizeof(struct counters_node));

  int i = 0;
  while (nodes[i] != NULL) {
	i++;
  }

  nodes[i] = node;
  node->key = key;
  node->count = count;
}

// code for intersection
static void and_merge (struct counters *ctrs1, struct counters *ctrs2)
{
  struct two_counters both = {ctrs1, ctrs2};
  counters_iterate(ctrs2, &both, and_iterate);
}

// counters_iterate function for and_merge
static void and_iterate (void *arg, int key, int count)
{
  struct two_counters *both = arg;
  int i = 0;
  if (count <= counters_get(both->c1, key)) {
	i = count;
  } else {
	i = counters_get(both->c1, key);
  }
  counters_set(both->c2, key, i);
}

// code for union
static void or_merge (struct counters *ctrs1, struct counters *ctrs2)
{
  counters_iterate(ctrs1, ctrs2, or_iterate);
}

// counters_iterate function for or_merge
static void or_iterate (void *arg, int key, int count)
{
  struct counters *ctrs2 = arg;
  int i = count + counters_get(ctrs2, key);
  counters_set(ctrs2, key, i);
}

// counters_iterate function to find the scores
static void total_counters (void *arg, int key, int count)
{
  int *i = arg;
  if (i != NULL) {
	(*i)++;
  }
}

// method used to delete counters objects:
static void clean_counters (void *item)
{ 
  struct counters *ctrs = item;
  counters_delete(ctrs);
}

// validating functions:
// validates command line arguments:
static void validate_parameters (int argc, char *argv[])
{
  if (argc != 3) {
    fprintf(stderr, "usage: %s pageDirectory indexFilename\n", argv[0]);
    exit(1);
  } else if (!is_crawled(argv[1])) {
    fprintf(stderr, "pageDirectory %s is not valid\n", argv[1]);
    exit(2);
  } else if (!validate_index_filename(argv[2])) {
    fprintf(stderr, "indexFilename %s is not valid\n", argv[2]);
    exit(3);
  }
}

// used by validate_parameters:
static bool validate_index_filename (const char *filename)
{
  FILE *fp = fopen(filename, "r");

  if (fp != NULL) {
    fclose(fp);
    return true;
  }
  return false;
}

// check to make sure no "and" or "or" tokens in the wrong places
static bool validate_query(char ** words, int count)
{
  if (!strcmp(words[0], "and")) {
    printf("Error: 'and' cannot be first\n");
    return false;
  } else if (!strcmp(words[0], "or")) {
    printf("Error: 'or' cannot be first\n");
    return false;
  }

  if (count > 1) {
    if (!strcmp(words[count-1], "and")) {
      printf("Error: 'and' cannot be last\n");
      return false;
    } else if (!strcmp(words[count-1], "or")) {
      printf("Error: 'or' canont be last\n");
      return false;
    }
  }

  // Quick legend for prev:
  // 0: previous word was not "and" or "or"
  // 1: previous word was "and"
  // 2: previous word was "or"
  int prev = 0;

  for (int i = 0; i < count; i++) {
    if (!strcmp(words[i], "and")) {
      if (prev == 0) {
        prev = 1;
      } else if (prev == 1) {
        printf("Error: 'and' and 'and' cannot be adjacent\n");
        return false;
      } else if (prev == 2) {
        printf("Error: 'and' and 'or' cannot be adjacent\n");
        return false;
      }
    } else if (!strcmp(words[i], "or")) {
      if (prev == 0) {
        prev = 2;
      } else if (prev == 1) {
        printf("Error: 'or' and 'and' cannot be adjacent\n");
        return false;
      } else if (prev == 2) {
        printf("Error: 'or' and 'or' cannot be adjacent\n");
        return false;
      }
    } else {
      prev = 0;
    }
  }
  return true;
}
