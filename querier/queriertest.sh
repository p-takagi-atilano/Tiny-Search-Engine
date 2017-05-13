#!/bin/bash
# Bash script for querier testing
# Paolo Takagi-Atilano, May 2017


# Make everything from top level directory:
make clean -C ../
make -C ../

# Do some crawling:
mkdir crawled
../crawler/crawler http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/ crawled 1

# Do some indexing to get started:
../indexer/indexer crawled out

# Do fuzztesting for querier:
./fuzzquery out 1000 0|querier crawled out
echo

# Do some things that should not work for various reasons:
./querier # Exit status 1
./querier wrong out # Exit status 2
./querier crawled wrong # Exist status 3

# Do some other things that should also not work, for other reasons:
echo and|querier crawled out
echo --------
echo or|querier crawled out
echo --------
echo duke and|querier crawled out
echo --------
echo duke or|querier crawled out
echo --------
echo duke and and duke|querier crawled out
echo --------
echo duke and or duke|querier crawled out
echo --------
echo duke or and duke|querier crawled out
echo --------
echo duke or or duke|querier crawled out
echo --------
echo 1--1|querier crawled out
echo --------
echo adsf-asdf|querier crawled out
echo --------
echo aajdsfjksafd|querier crawled out
echo --------
