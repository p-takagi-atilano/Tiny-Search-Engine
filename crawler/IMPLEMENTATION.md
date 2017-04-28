#Implementation for crawler.c
##Paolo Takagi-Atilano, April 2017

The TSE crawler is a standalone program that crawls the web and retrieves webpages starting from a "seed" URL. It parses the seed webpage, extracts any embedded URLs, then retrieves each of those pages, but limiting its exploration to a given "depth".

**Pseudo code:**

The crawler will run as follows:

1. excute from a command line as shown in the User Interface
2. parse the command line, validate parameters, initialize other modules
3. make a *webpage* for the `seedURL`
4. add that page to the *bag* of webpages to crawl
5. add that URL to the *hashtable* of URLs seen
6. while there are more webpages to crawl,
	1. extract a webpage (URL,depth) item from the *bag* of webpages to be crawled,
	2. pause for at least one second
	3. use *pagefetcher* to retrieve a webpage for that URL,
	4. use *pagesaver* to write the webpage to the `pageDirectory ` with a unique document ID (an int that increments each time)
	5. if the webpage depth is < `maxDepth`, explore the webpage to find links:
		1. use *pagescanner* to parse the webpage to extract all of its embedded URLs;
		2. for each extracted URL,
			1. 'normalize' the URL
			2. if that URL is not 'internal' ignore it
			3. try to insert that URL into the *hashtable* of URLs seen	
				1. If it was already in the table, do nothing;
				2. if it was added to the table,
					1. make a new *webpage* for that URL, at depth+1
					2. add the new webpage to the *bag* of webpages to be crawled

**Normalize the URL** means to convert it into a clean, canonical form.
**Internal** means that the URL stats within the CS50 playground (http://old-www.cs.dartmouth.edu). 


**Data Structures:**

**Webpage:** holds the url as a string, depth in an integer, and html as a string

**Bag:** a bag is an unordered collection of (items).  the bag starts empty, grows as the caller adds one item at a time, and shrinks as the caller extracts one item at a time.  It could be empty, or could contain hundreds of items.  Items are indistinguishable, so the extract function is free to return any item from the bag.

- For the purposes of crawler, the bag holds webpage structs.

**Hashtable:** a *hashtable* is a set of (key,item) pairs. It acts just like a set, but is far more efficient for large collections.

- For the purposes of this lab, the hashtable stores urls of webpages that have already been visited.

**Set:** a set maintains an unordered collection of (key,item) pairs; any given key can ony occur in the set once. It starts out empty and grows as the caller inserts new (key,item) pairs.  The caller can retrieve items by asking for their key, but cannot or remove or update pairs. Items are distinguished by their key.

**Being Polite:**

To be polite, my crawler purposely slows its behavior by introducing a delay, sleeping for one second between fetches.  Furthermore, my crawler will limit its crawl to a specific web server inside CS, so we don't bother any other servers on campus or beyond.

**Error Handling:**

If there is an issue with given arguments, the crawler will sasy what is wrong and not run.  If ther are any issues with the website visited (could not be connected to, not internal url, etc), they will be ignored.

**Persistant Storage:**

Webpages are stored in given `pageDirectory` as individual files, and thus are persistant.
