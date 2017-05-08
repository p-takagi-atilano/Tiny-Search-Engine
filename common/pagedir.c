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
#include "webpage.h"
#include "file.h"

// crawler uses to see if directory exists
/**************** test_dir() ****************/
bool test_dir (char *dirname)
{
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

// indexer uses to see if directory exists/made by crawler
/**************** is_crawled() ****************/
bool is_crawled(const char *page_directory)
{ 
  char *file = "/.crawler";
  char filename[sizeof(page_directory) + sizeof(file)+ 2];
  strcpy(filename, page_directory);
  strcat(filename, file);

  FILE *fp = fopen(filename, "r");
  //free(filename);
  if (fp != NULL) {
    fclose(fp);
    return true;
  }
  return false;
}

// indexer uses to load webpage struct from files
/**************** load_page() ****************/
struct webpage *
load_page(const char *page_directory, const char *index_filename)
{
  char filename[5 + sizeof(page_directory) + sizeof(index_filename)];
  strcpy(filename, page_directory);
  strcat(filename, "/");
  strcat(filename, index_filename);

  //fprintf(stdout, "filename: %s\n", filename);

  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
	return NULL;
  }

  char *url = readlinep(fp);
  char *depth_str = readlinep(fp);
  char *html = readfilep(fp);
  if (url == NULL || depth_str == NULL || html == NULL) {
    return NULL;
  }
  
  int depth = -1;

  sscanf(depth_str, "%d", &depth);
  
  struct webpage *page = webpage_new(url, depth, html);
  if (page == NULL) {
	return NULL;
  }
  free(url);
  //free(html);
  free(depth_str);
  fclose(fp);
  return page;
}
