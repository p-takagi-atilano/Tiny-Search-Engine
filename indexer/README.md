#Indexer README.md
##Paolo Takagi-Atilano, May 2017
###Compiling:
In order to compile, run `make` from the `tse` directory.  This will make sure that all the necessary libraries are made before anything is attempted with `indexer`. In order to run `indextest.sh` please navigate to the indexer directory from the tse directory, and do `./indextest.sh`.  The screen will output a lot of stuff, but most important is that the bottom lame says that the last few lines that indicate successes

###Usage:
./indexer pageDirectory indexFilename

###Assumptions:
- pageDirectory has a `.crawler` file in it to verify that it was created by `crawler` module.
- pageDirectory contains pages from crawler module output
- A word is a collection of letters

###Exit Statuses:
0 - Success

1 - Usage Error

2 - pageDirectory is not valid

3 - indexFilename is not valid

4 - hashtable_new failed
