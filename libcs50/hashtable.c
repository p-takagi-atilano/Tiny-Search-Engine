/*
 * hashtable.c - CS50 'hashtable' module
 * see hashtable.h for more information.
 *
 * Paolo Takagi-Atilano, April 2017
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "hashtable.h"
#include "set.h"
#include "memory.h"
#include "jhash.h"

/**************** file-local global variables ****************/
/* none */

/**************** local types ****************/
/* none */

/**************** global types ****************/
typedef struct hashtable {
  int num_slots;
  struct set **array;
} hashtable_t;

/**************** global functions ****************/
/* that is, visible outside this file */
/* see hashtable.h for comments about exported functions */

/**************** local functions ****************/
/* not visible outside this file */


/**************** hashtable_new() ****************/
hashtable_t *
hashtable_new(const int num_slots)
{
  if (num_slots <= 0) {
	return NULL;
  }

  hashtable_t *ht = count_malloc(sizeof(hashtable_t));
  ht->array = count_malloc(num_slots*(sizeof(struct set*)));
  if (ht == NULL) {
	return NULL; // error allocating hashtable
  } else {
	ht->num_slots = num_slots;

	for (int i = 0; i < num_slots; i++) {
      struct set *s = set_new(); 
	  if (s == NULL) {
		return NULL; // error allocating set slot of hashtable
	  }
	  ht->array[i] = s;
	}
	return ht;
  }
}

/**************** hashtable_insert() ****************/
bool
hashtable_insert(hashtable_t *ht, const char *key, void *item)
{
  if (ht != NULL && key != NULL && item != NULL) {
	unsigned long i = JenkinsHash(key, ht->num_slots);
	if (ht->array[i] != NULL && set_find(ht->array[i], key) == NULL) {
	  set_insert(ht->array[i], key, item);
	  return true;
	}
  }
  return false;
}

/**************** hashtable_find() ****************/
void *
hashtable_find(hashtable_t *ht, const char *key)
{
  if (ht != NULL && key != NULL) {
	int i = JenkinsHash(key, ht->num_slots);
	void *temp = set_find(ht->array[i], key);
	if (temp != NULL) {
	  return temp;
	}
  }
  return NULL;
}

/**************** hashtable_print() ****************/
void
hashtable_print(hashtable_t *ht, FILE *fp,
			void (*itemprint)(FILE *fp, const char *key, void *item) )
{
  if (fp != NULL) {
	if (ht != NULL) {
	  fputc('[', fp);
	  for (int i = 0; i < ht->num_slots; i++) {
		set_print(ht->array[i], fp, itemprint);
	  }
	  fputc(']', fp);
	} else {
	  fputs("(null)", fp);
	}
  }
}

/**************** hashtable_iterate() ****************/
void
hashtable_iterate(hashtable_t *ht, void *arg, 
			void (*itemfunc)(void *arg, const char *key, void *item) )
{
  if (ht != NULL) {
	for (int i = 0; i < ht->num_slots; i++) {
	  set_iterate(ht->array[i], arg, itemfunc);
	}
  }
}

/**************** hashtable_delete() ****************/
void
hashtable_delete(hashtable_t *ht, void (*itemdelete)(void *item) )
{
  if (ht != NULL) {
	for (int i = 0; i < ht->num_slots; i++) {
	  set_delete(ht->array[i], itemdelete);
	}
	count_free(ht->array);
	count_free(ht);
  }

#ifdef MEMTEST
	count_report(stdout, "End of hashtable_delete");
#endif
}
