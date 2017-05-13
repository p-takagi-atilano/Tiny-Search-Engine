#Querier Implementation Spec
##Paolo Takagi-Atilano, May 2017
**Data Structures:**

- An index is loaded from the index file that was created by `indexer` module.  It is implemented the same way that such an index was implemented for `indexer`, that is a hashtable of counters, where the key is the word and the counters represent documents and the frequency of the word in each document.  

- Next, we need to store all the tokens created from tokenizing the imput string (using whitespace as a delimeter and the `strtok()` method).  In order to do this, I chose to use a `char **`.  Each `char *` in this `char **` is a word token.  

- Each word (assuming that it is present in the inverse index hashtable and that it is not "and" or "or") represents a `counters` object, in which the key is the file in which the word appeared, and the count is the number of times that word appeared in that file.  Simply by using `hashtable_find()` we can access that said `counters` data structure.

- From all of these `counters` objects for each of the words in the query line, we need to merge them into a single `counters` object, which represents the results returned for this specific query.  In order to do this, I utilized Backus-Naur Form, with two counters objects, one called `ands` which represented the andsequence, and one called `ors` which represented the query.  With the right logic and algorithms (outlined below in pseudo code), we can turn that into a single `counters` object, which shows all the results of the inputted query.

**Pseudo Code:**

*build_query:*

- iterate through each word token in `char ** words`
	- if word is "and", ignore it (remember that there is an assumed and between each word anyways, so typing in "and" pretty much does nothing)
	- if this is the first word, or the previous word is "or"
		- if the word can be found in the index
		- make `ands` a new counters object, and add the current word token
	- if current word token is or:
		- if `ors` currently exists (has information)
			- if `ands` currently exists (has information)
				- union `ors` and `ands`
		- else `ors` has no information
			- if `ands` has information
				- make `ors` a new counters object
				- union `ands` and `ors`
		- if `ands` exists (all pertinent previous `ands` information is now in `ors`, so we can reset `ands` for the next `andsequence`)
			- delete `ands`, set it to null
	- if cannot find current word token in index
		- if `ands` exists and has information
			- delete `ands` set it to null (all important info should be in `ors` so we are not losing anything)
	- else can find current word token in index
		- if ands is not null
			- intersect current word token's associated `counters` object to ands
- if there is information in `ors`
	- if there is no information in `ands`
		- create new `ands` and union it with `ors`

*sorting queries:* 

- I chose to use qsort, and used each node's `count` value in the given `counters` objects (final `ands` from `build_query()`) to rank them

*union two `counters` objects:*

- iterate through one of the `counters` objects, add all of that to the other `counters` object.  Return the second `counters` object.  If any same `keys` for both `counters` objects, set their corresponding `count` to the sum of the two respective `count`s

*intersection:*

- same as `union`, except take the minimum `count` value instead of the total of both of them.  Remember, if a `counters` object does not have a certain item, that is trying to be got from it, it will give a zero value.  Hence, we are quite potentially adding some zero values into a counters object, unless every match for one word is also every match for the other word.  That is ok, we just have to ignore the zero values in the final `counters` object later. 
