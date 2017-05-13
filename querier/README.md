#Querier README.md
##Paolo TAkagi-Atilano, May 2017
###Compiling:
In order to compile, run `make` from the `tse` directory.  This will make sure that all the necessary libraries are made before anything is attempted with `querier`.

###Usage:
./querier pageDirectory indexFilename

###Assumptions:
- `pageDirectory` has filves named 1, 2, 3, ..., without gaps.
- The content of files in `pageDirectory` follow the format as defined in the specs
- The content of the file named by `indexFilename` follows out Index file format

###Exit Statuses:
0 - Success
1 - Usage error
2 - pageDirectory is not valid
3 - indexFilename is not valid
4 - hashtable_new failed
5 - index_load failed
6 - failed to allocate space for `words`
