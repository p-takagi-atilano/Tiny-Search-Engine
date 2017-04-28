/*
 * set.c - CS50 'set' module
 *
 * see set.h for more information.
 *
 * Paolo Takagi-Atilano, April 2017
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set.h"
#include "memory.h"

/**************** file-local global variables ****************/
/* none */

/**************** local types ****************/
typedef struct setnode {
  char *key;				// key (string)
  void *item;				// pointer to data for this item
  struct setnode *next;			// link to next node
} setnode_t;

/**************** global types ****************/
typedef struct set {
  struct setnode *head;			// head of the list of items in set
} set_t;

/**************** global functions ****************/
/* that is, visible outside this file */
/* see set.h for comments about exported functions */

/**************** local functions ****************/
/* not visible outside this file */
static setnode_t *setnode_new(const char *key, void *item);

/**************** set_new() ****************/
set_t *
set_new(void)
{
  set_t *set = count_malloc(sizeof(set_t));
  if (set == NULL) {
	return NULL; // error allocating set
  } else {
	// initialize contents of set structure
	set->head = NULL;
	return set;
  }
}

/**************** set_insert() *************/
bool 
set_insert(set_t *set, const char *key, void *item)
{
	if (set != NULL && key != NULL && item != NULL) {
	  if (set_find(set, key) == NULL) { // make sure key doesn't exist
		// allocate a new node to be added to list
		setnode_t *new = setnode_new(key, item);
		if (new != NULL) {
		  // add it to the head of the list
		  new->next = set->head;
		  set->head = new;

		#ifdef MEMTEST
		  count_report(stdout, "After set_insert");
		#endif
		
		return true;
		}
	  }
	}
	return false;
}

/**************** setnode_new **************/
/* Allocate and initialize a setnode */
static setnode_t * // not visible outside this file
setnode_new(const char *key, void *item)
{
  setnode_t *node = count_malloc(sizeof(setnode_t));
  
  if (key == NULL || item == NULL) {
	return NULL;
  }

  if (node == NULL) {
	// error allocating memory for node; return error
	return NULL;
  } 

  node->key = count_malloc(strlen(key)+1);
  if (node->key == NULL) {
	// error allocating memory for key;
	// cleanup and return error
	count_free(node);
	return NULL;
  } else {
	strcpy(node->key, key);
	node->item = item;
	node->next = NULL;
	return node;
  }
}

/**************** set_find() ***************/
void *
set_find(set_t *set, const char *key)
{
  if (set != NULL && key != NULL) {
	// iterate through set
	for (setnode_t *node = set->head; node != NULL; node = node->next) {
	  if (strcmp(node->key, key) == 0) {
		return node->item;
	  }
	}
  }
  return NULL;
}

/**************** set_print() **************/
void
set_print(set_t *set, FILE *fp,
		void (*itemprint)(FILE *fp, const char *key, void *item) )
{
  if (fp != NULL) {
	if (set != NULL) {
		fputc('{', fp);
		for (setnode_t *node = set->head; node != NULL; node = node->next) {
	  // print this node
	  if (itemprint != NULL) {	// print the node's key and  item
		(*itemprint)(fp, node->key, node->item);
		fputc(',', fp);
	  }
		}
		fputc('}', fp);
	} else {
		fputs("(null)", fp);
	}
  }
}

/**************** set_iterate() ************/
void
set_iterate(set_t *set, void *arg, 
			void (*itemfunc)(void *arg, const char *key, void *item) )
{
  if (set != NULL && itemfunc != NULL) {
	// call itemfunc with arg, on each item
	for (setnode_t *node = set->head; node != NULL; node = node->next) {
	  (*itemfunc)(arg, node->key, node->item);
    }
  }
}

/**************** set_delete() *************/
void
set_delete(set_t *set, void (*itemdelete)(void *item) )
{
  if (set != NULL) {
	for (setnode_t *node = set->head; node != NULL; ) {
	  if (itemdelete != NULL) {			// if possible
		(*itemdelete)(node->item);		// delete node's item
	  }
	  setnode_t *next = node->next;     // remember what comes next
	  count_free(node->key);
	  count_free(node);				// free the node
	  node = next;
	} 
  count_free(set);
  }

#ifdef MEMTEST
  count_report(stdout, "End of set_delete");
#endif
}


