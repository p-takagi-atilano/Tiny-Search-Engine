#README for crawler.c
## Paolo Takagi-Atilano, April 2017
**Compiling:**

	make
**Usage:**

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
**Example Command Lines:**
	
	./crawler http://old-www.cs.dartmouth.edu/~dfk crawled 0
	./crawler http://old-www.cs.dartmouth.edu/~dfk crawled 1
	./crawler http://old-www.cs.dartmouth.edu/index.html ./data/ 2
	
**Assumptions:**

- pageDirectory already exists

**"Non"-Assumptions:**

- Can handle non-Integer or < 0 values for maxDepth (exits)

**Limitations:**

- Does not create a pageDirectory if it already exists
