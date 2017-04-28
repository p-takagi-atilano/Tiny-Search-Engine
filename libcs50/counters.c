/* 
 * counters.c - CS50 'counters' module
 *
 * see counters.h for more information.
 *
 * Paolo Takagi-Atilano, April 2017
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counters.h"
#include "memory.h"

/**************** file-local global variables ****************/
/* none */

/**************** local types ****************/
typedef struct countersnode {
  int key;						// key (int)
  int count;					// count (int)
  struct countersnode *next;			// link to next node
} countersnode_t;

/**************** global types ****************/
typedef struct counters {
  int next_key;
  struct countersnode *head;	// head of the list of items in counters
} counters_t;

/**************** global functions ****************/
/* that is, visible outside this file */
/* see counters.h for comments about exported functions */

/**************** local functions ****************/
/* not visible outside this file */
static countersnode_t *countersnode_new(int key, int count);

/**************** counters_new() ****************/
counters_t *
counters_new(void)
{
  counters_t *ctrs = count_malloc(sizeof(counters_t));

  if (ctrs == NULL) {
	return NULL; // error allocating set
  } else {
	// initialize contents of counters structure
	ctrs->head = NULL;
	return ctrs;
  }
}

/**************** counters_add() ****************/

void
counters_add(counters_t *ctrs, const int key)
{
  if (ctrs != NULL && key >= 0) {
    for (countersnode_t *node = ctrs->head; node != NULL; ) {
	  if (node->key == key) {
		(node->count)++;
		return;
	  }
	  node = node->next;
    }
	// allocate a new node to be added to list
	countersnode_t *new = countersnode_new(key, 1);
	if (new != NULL) {
	  // add it to the head of the list
	  new->next = ctrs->head;
	  ctrs->head = new;

	#ifdef MEMTEST
	  count_report(stdout, "After counters_add");
	#endif
	}
  }
}

/**************** countersnode_new() ************/
/* Allocate and initialize a countersnode */
static countersnode_t * // not visible outside this file
countersnode_new(const int key, int count)
{
  countersnode_t *node = count_malloc(sizeof(countersnode_t));

  if (node == NULL) {
	// error allocating memory for node; return error
	return NULL;
  } else {
	node->key = key;
	node->count = count;
	node->next = NULL;
	return node;
  }
}

/**************** counters_get() ****************/
int
counters_get(counters_t *ctrs, const int key)
{
  if (ctrs != NULL && key >= 0) {
	for (countersnode_t *node = ctrs->head; node != NULL; ) {
	  if (node->key == key) {
		return node->count;
	  }
	  node = node->next;
	}
  }
  return 0;
}

/**************** counters_set() ****************/
void
counters_set(counters_t *ctrs, const int key, int count)
{
  if (ctrs != NULL && key >= 0 && count >= 0) {
    for (countersnode_t *node = ctrs->head; node != NULL; ) {
      if (node->key == key) {
        node->count = count;
		return;
      }
      node = node->next;
    }
      countersnode_t *new = countersnode_new(key, count);
      if (new != NULL) {
        // add it to the head of the list
        new->next = ctrs->head;
        ctrs->head = new;

      #ifdef MEMTEST
        count_report(stdout, "After counters_add");
      #endif
    }
  }
}

/**************** counters_print() **************/
void
counters_print(counters_t *ctrs, FILE *fp)
{
  if (fp != NULL) {
	if (ctrs != NULL) {
	  fputc('{', fp);
	  for (countersnode_t *node = ctrs->head; node != NULL; node = node->next) {
		fprintf(fp, "%d:%d", node->key, node->count);
		fputc(',', fp);
	  }
	  fputc('}', fp);
	} else {
	  fputs("(null)", fp);
	}
  }
}

/**************** counters_iterate() ***********/
void
counters_iterate(counters_t *ctrs, void *arg,
		void (*itemfunc)(void *arg, const int key, int count))
{
  if (ctrs != NULL && itemfunc != NULL) {
	//call imtemfunc with arg, on each item
	for (countersnode_t *node = ctrs->head; node != NULL; node = node->next) {
	  (*itemfunc)(arg, node->key, node->count);
	}
  }
}

/**************** counters_delete() ************/
void 
counters_delete(counters_t *ctrs)
{
  if (ctrs != NULL) {
	for (countersnode_t *node = ctrs->head; node != NULL; ) {
	  countersnode_t *next = node->next;	// remember what comes next
	  count_free(node);						// free the node
	  node = next;
	}
	count_free(ctrs);
  }

#ifdef MEMTEST
  count_report(stdout, "End of counters_delete");
#endif
}
