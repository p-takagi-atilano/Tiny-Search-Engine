#Indexer DESIGN.md
##Paolo Takagi-Atilano, May 2017
The `indexer` module reads documents in the `pageDirectory` output by the `crawler`.  It then builds an inverted index mapping from words to documents, and writes that index to a file.  The `querier` module will read the index and use it to answer queries.

###Inverted Index:

It is necessary to have a data structure represent the inverted index.  It is called an *inverted* index because it maps from words to documents, which is the opposite of a document (a sequence of words).  See IMPLEMENTATION.md to see what we used.
