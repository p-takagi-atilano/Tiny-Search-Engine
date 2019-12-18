#!/bin/bash
# integration testing of crawler.c
# pageDirectory must be called 'crawled'
# program must be called crawler
#
# if you want to see what file output looks like for one of these tests,
# feel free to comment out everything under it and run the script
#
# Paolo Takagi-Atilano, April 2017

#1
echo "bad usages:"
crawler
crawler http://old-www.cs.dartmouth.edu/index.html ./data/ 2
crawler http://old-www.cs.dartmouth.edu/index.html crawled asdf
crawler http://old-www.cs.dartmouth.edu/index.html crawled -1
echo

#2
echo "seedURL points to non-existent server:"
crawler http://www.ihopethatthisdoesntwork.com crawled 1
echo

#3
echo "seedURL points to non-internal server:"
crawler http://www.google.com crawled 1
rm -f crawled/*
echo

#4
echo "seedURL points to valid server but non-existent page:"
crawler http://old-www.cs.dartmouth.edu/blahblahblah crawled 1

#5
echo "crawling loops and stuff:"
crawler http://old-www.cs.dartmouth.edu/~dfk crawled 2
rm -f crawled/*
echo

#6
echo "crawling a lot more:"
crawler http://old-www.cs.dartmouth.edu/index.html crawled 0
rm -f crawled/*
crawler http://old-www.cs.dartmouth.edu/index.html crawled 1
rm -f crawled/*
crawler http://old-www.cs.dartmouth.edu/index.html crawled 2
rm -f crawled/*
crawler http://old-www.cs.dartmouth.edu/index.html crawled 3
rm -f crawled/*
crawler http://old-www.cs.dartmouth.edu/index.html crawled 4
rm -f crawled/*
crawler http://old-www.cs.dartmouth.edu/index.html crawled 5
rm -f crawled/*
echo

#7
echo "crawling with a new seed:"
crawler http://old-www.cs.dartmouth.edu/~dfk/people.html crawled 2
rm -f crawled/*
echo

#8
echo "crawling our Wikipedia playground:"
crawler http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/ crawled 0
rm -f crawled/*
crawler http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/ crawled 1
rm -f crawled/*
crawler http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/ crawled 2
rm -f crawled/*
echo

#9
echo "crawling on our playground:"
crawler http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/ crawled 2
rm -f crawled/*
