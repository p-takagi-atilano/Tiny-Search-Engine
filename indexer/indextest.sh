#!/bin/bash
# 
# indextest.sh - test indexer program
# 
# usage indextest.sh
# 
# input: nothing
# output: results of tests and stuff
# 
# Paolo Takagi-Atilano, May 2017

# use crawler to get some stuff to index:
mkdir crawled
../crawler/crawler http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/ crawled 1

# try a stupid usage:
./indexer
#echo *********
# try an invalid directory: 
./indexer adfjafdsijafdsljafds index

# I don't know how to provide an invalid indexFilename

# try one that is intended to work, make index file called out
./indexer crawled out

# use indextest to do unit test stuff, make index file called check:
./indextest out check

# sort both out and check
gawk -f indexsort.awk out > out.sorted
gawk -f indexsort.awk check > check.sorted

# check to see if they are the same, they should not differ:
diff -s out.sorted check.sorted

