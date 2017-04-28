/*
 * crawler.c - The TSE crawler is a standalone program that crawls the web and
 * retrieves webpages starting from a "seed" URL. It parses the seed webpage, 
 * extracts any embedded URLs, then retrieves ecch of those pages, limiting
 * its exploration to a given "depth".
 * ^From CS50 Spring 2017 TSE Crawler Requirements Spec
 *
 * usage: ./crawler seedURL pageDirectory maxDepth
 *
 * stdin: nothig
 * stdout: real time info about what is happeing to different webpages
 * stderr: error messages
 *
 * Exit Statuses:
 * 0-Success
 * 1-Usage Error
 * 2-Could not locate fiven pageDirectory
 * 3-maxDepth is not integer
 * 4-maxDepth is not >= 0
 *
 * Paolo Takagi-Atilano, April 2017
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bag.h"
#include "hashtable.h"
#include "pagedir.h"
#include "webpage.h"

/* Function prototypes */
void crawler(bag_t *pages, hashtable_t *urls, 
		const char *dirname, const int maxDepth);
bool page_saver(const char *filename, webpage_t *page);

/* main */
int main (const int argc, char *argv[])
{
  int hashtable_slots = 10;
  int max_depth = -1;
  char *ptr = "";

  // validating parameters:
  if (argc != 4) {
	fprintf(stderr, "usage: crawler seedURL pageDirectory maxDepth\n");
	exit(1);
  }

  if (!test_dir(argv[2])) {
	fprintf(stderr, "could not find given pageDirectory\n");
	exit(2);
  }
  const char *pagedir = argv[2];
    
  if (sscanf(argv[3], "%d %s", &max_depth, ptr) != 1) {
	fprintf(stderr, "usage: maxDepth must be an int\n");
	exit(3);
  } else if (max_depth < 0) {
	fprintf(stderr, "usage: maxDepth must be >= 0\n");
	exit(4);
  }
  
  // creating bag and hashtable
  bag_t *pages = bag_new();	// bag of pages we have yet to explore
  // hashtable of URLs we've seen so far:
  hashtable_t *urls = hashtable_new(hashtable_slots);

  // setting stuff up for crawler
  struct webpage *page = webpage_new(argv[1], 0, NULL);
  bag_insert(pages, page);
  hashtable_insert(urls, argv[1], argv[1]);

  // running crawler:
  crawler(pages, urls, pagedir, max_depth);

  // cleaning up:
  bag_delete(pages, webpage_delete);
  hashtable_delete(urls, NULL);
}

/*
 * the method that does everything described at the top of this file
 */
void crawler(bag_t *pages, hashtable_t *urls, const char *dirname, const int maxDepth) 
{
  int id = 1;
  webpage_t *page = bag_extract(pages);
  // while there are still pages in bag
  while(page != NULL) {
	// try to fetch html from webpage
	if (webpage_fetch(page)) {
	  printf("%d   Fetched: %s\n", 
			webpage_getDepth(page), webpage_getURL(page));
	  // setting up parameters for page_saver
	  char filename[sizeof(dirname) + 25] = "";
	  char temp[25];
	  strcat(filename, dirname);
      strcat(filename, "/");
	  sprintf(temp, "%d", id);
	  strcat(filename, temp);
	  // try to save page
	  if (page_saver(filename, page)) {
		printf("%d     Saved: %s\n",
			webpage_getDepth(page), webpage_getURL(page));
	  }
	  id++; // increment id for next time
	  // check to see we haven't hit the bottom of the pool
	  if (webpage_getDepth(page) < maxDepth) {
		int pos = 0;
		char *result;
		printf("%d  Scanning: %s\n", 
			webpage_getDepth(page), webpage_getURL(page));
		// scanning for embedded URLs
		while ((pos = webpage_getNextURL(page, pos, &result)) > 0) {
		  printf("%d     Found: %s\n", webpage_getDepth(page), result);
		  // check to see if URL is internal
		  if (IsInternalURL(result)) {
			// check to see if URL has already been visited
			// (if it can be inserted into hashtable succesfully,
			// it hasn't already been visited
		    if (hashtable_insert(urls, result, result)) {
			   // making webpage and adding it to bag
			   webpage_t *found = webpage_new (result,
								webpage_getDepth(page)+1, NULL);
			
			  bag_insert(pages, found);
			  printf("%d     Added: %s\n", 
					webpage_getDepth(page), result);
			}
		  } else { // ignore external URL
			printf("%d  IgnExtrn: %s\n", webpage_getDepth(page), result);
		  }
		  free(result); // clean up
		}
	  }
	} else { // couldn't connect to URL
	  printf("    FAILED: %s\n", webpage_getURL(page));
	}
	// free memory associated with page, then extract the next one
	webpage_delete(page);
	page = bag_extract(pages);
  }
}

/*
 * given a filename (string) and a point to webpage struct,
 * if no null pointers or errors will write info to given filename like so:
 * url
 * depth
 * html
 *
 * else return false
 */
bool page_saver(const char *filename, webpage_t *page)
{
  if (filename != NULL && page != NULL && webpage_getHTML(page) != NULL) {
    FILE *fp = fopen(filename, "w");
	if (fp != NULL) {
	  fprintf(fp, "%s\n", webpage_getURL(page));
	  fprintf(fp, "%d\n", webpage_getDepth(page));
	  fprintf(fp, "%s", webpage_getHTML(page));
	  fclose(fp);
	  return true;
 	}
  }
  return false;
}
