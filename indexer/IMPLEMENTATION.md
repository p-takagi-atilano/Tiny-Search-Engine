#Index IMPLEMENTATION.md
##Paolo Takagi-Atilano, May 2017

###Data Structure:
For the indexer module, an inverted index is needed, which maps each word to the files in which it is found.  I decided that a hashmap of counters would be an effective data structure.  Essentially we need a way to store a bunch of words as keys, and their corresponding counters objects (which represent which webpage the words are found in, and how many times) as the item.  I do not think bags would be effective, because I think that I will have to make use of finding items, instead of just taking what I can get.  That leaves two other obvious options, set and hashtable.  I chose to use hashtable because it is faster, and if I am mantaining a large inverted index with many different entries, using a set could become costly, because I would have to iterate linearly through the entire set until I found the right word.

###Pseudo Code:
**index_build(directory,*index*):**

1. start with id 1, attempt to create webpage from `load_page` at directory/id called page
2. while page != NULL
	1. while page has more words
		1. if given word is longer than 2 chars
			1. normalize it
				- if counters object in index exists with key of word
					- increment counters by one
				- else 
					- create new counters object, and insert into index with key of word



**index_save(filename,*index*):**

1. open file with string filename for writing
2. iterate through hashtable and do the following:
	1. print key and then a space into the file
	2. iterate through counters struct associated with key and do the following:
		- print key and then space and then count and then space (key and count come from specific counters node) into the file
	3. print a new line into the file
3. close the file
