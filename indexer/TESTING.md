# Indexer Testing.md
## Paolo Takagi-Atilano
Note that while some files already existed, it is ok becaause they got replaced by new version of that file anyways.

### getting to right place
[paolo@flume ~]$ cd cs50/labs/tse/

### cleaning up everything
[paolo@flume ~/cs50/labs/tse]$ make clean
rm -f *~
rm -f TAGS
make -C libcs50 clean
make[1]: Entering directory '/net/tahoe3/paolo/cs50/labs/tse/libcs50'
rm -f libcs50.a *~ *.o
make[1]: Leaving directory '/net/tahoe3/paolo/cs50/labs/tse/libcs50'
make -C common clean
make[1]: Entering directory '/net/tahoe3/paolo/cs50/labs/tse/common'
rm -f common.a *~ *.o
make[1]: Leaving directory '/net/tahoe3/paolo/cs50/labs/tse/common'
make -C crawler clean
make[1]: Entering directory '/net/tahoe3/paolo/cs50/labs/tse/crawler'
rm -f *~ *.o *.dSYM
rm -f crawler
make[1]: Leaving directory '/net/tahoe3/paolo/cs50/labs/tse/crawler'
make -C indexer clean
make[1]: Entering directory '/net/tahoe3/paolo/cs50/labs/tse/indexer'
rm -f *~ *.o *.dSYM
rm -f indexer
rm -f indextest
make[1]: Leaving directory '/net/tahoe3/paolo/cs50/labs/tse/indexer'
make -C querier clean
make[1]: *** querier: No such file or directory.  Stop.
Makefile:28: recipe for target 'clean' failed
make: *** [clean] Error 2

### making everything over again (querier fails because it doesn't exist yet)
[paolo@flume ~/cs50/labs/tse]$ make
make -C libcs50
make[1]: Entering directory '/net/tahoe3/paolo/cs50/labs/tse/libcs50'
gcc -Wall -pedantic -std=c11 -ggdb    -c -o bag.o bag.c
gcc -Wall -pedantic -std=c11 -ggdb    -c -o counters.o counters.c
gcc -Wall -pedantic -std=c11 -ggdb    -c -o file.o file.c
gcc -Wall -pedantic -std=c11 -ggdb    -c -o hashtable.o hashtable.c
gcc -Wall -pedantic -std=c11 -ggdb    -c -o jhash.o jhash.c
gcc -Wall -pedantic -std=c11 -ggdb    -c -o memory.o memory.c
gcc -Wall -pedantic -std=c11 -ggdb    -c -o set.o set.c
gcc -Wall -pedantic -std=c11 -ggdb    -c -o webpage.o webpage.c
gcc -Wall -pedantic -std=c11 -ggdb    -c -o webpage_fetch.o webpage_fetch.c
ar cr libcs50.a bag.o counters.o file.o hashtable.o jhash.o memory.o set.o webpage.o webpage_fetch.o
make[1]: Leaving directory '/net/tahoe3/paolo/cs50/labs/tse/libcs50'
make -C common
make[1]: Entering directory '/net/tahoe3/paolo/cs50/labs/tse/common'
gcc -Wall -pedantic -std=c11 -ggdb -I../libcs50   -c -o pagedir.o pagedir.c
gcc -Wall -pedantic -std=c11 -ggdb -I../libcs50   -c -o index.o index.c
gcc -Wall -pedantic -std=c11 -ggdb -I../libcs50   -c -o word.o word.c
ar cr common.a pagedir.o index.o word.o
make[1]: Leaving directory '/net/tahoe3/paolo/cs50/labs/tse/common'
make -C crawler
make[1]: Entering directory '/net/tahoe3/paolo/cs50/labs/tse/crawler'
gcc -Wall -pedantic -std=c11 -ggdb -I../libcs50 -I../common -lcurl   -c -o crawler.o crawler.c
gcc -Wall -pedantic -std=c11 -ggdb -I../libcs50 -I../common -lcurl crawler.o ../common/common.a ../libcs50/libcs50.a -o crawler
make[1]: Leaving directory '/net/tahoe3/paolo/cs50/labs/tse/crawler'
make -C indexer
make[1]: Entering directory '/net/tahoe3/paolo/cs50/labs/tse/indexer'
gcc -Wall -pedantic -std=c11 -ggdb -I../libcs50 -I../common   -c -o indexer.o indexer.c
gcc -Wall -pedantic -std=c11 -ggdb -I../libcs50 -I../common indexer.o ../common/common.a ../libcs50/libcs50.a -o indexer
gcc -Wall -pedantic -std=c11 -ggdb -I../libcs50 -I../common   -c -o indextest.o indextest.c
gcc -Wall -pedantic -std=c11 -ggdb -I../libcs50 -I../common indextest.o ../common/common.a ../libcs50/libcs50.a -o indextest
make[1]: Leaving directory '/net/tahoe3/paolo/cs50/labs/tse/indexer'
make -C querier
make[1]: *** querier: No such file or directory.  Stop.
Makefile:10: recipe for target 'all' failed
make: *** [all] Error 2

### moving to indexer and showing contents
[paolo@flume ~/cs50/labs/tse]$ cd indexer
[paolo@flume ~/cs50/labs/tse/indexer]$ ls
check	      DESIGN.md		 indexer.c	 indextest*   indextest.sh*  out.sorted
check.sorted  IMPLEMENTATION.md  indexer.o	 indextest.c  Makefile	     README.md
crawled/      indexer*		 indexsort.awk*  indextest.o  out	     TESTING.md

### running indextest.sh
[paolo@flume ~/cs50/labs/tse/indexer]$ indextest.sh
mkdir: cannot create directory ‘crawled’: File exists
0   Fetched: http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/
0     Saved: http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/
0  Scanning: http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/
0     Found: http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
0     Added: http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
0     Found: http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
0     Added: http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
0     Found: http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
0     Added: http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
0     Found: http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
0     Added: http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
0     Found: http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
0     Added: http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
0     Found: http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
0     Added: http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
1   Fetched: http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
1     Saved: http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
1   Fetched: http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
1     Saved: http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
1   Fetched: http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
1     Saved: http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
1   Fetched: http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
1     Saved: http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
1   Fetched: http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
1     Saved: http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
1   Fetched: http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
1     Saved: http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
usage: ./indexer pageDirectory indexFilename
pageDirectory adfjafdsijafdsljafds is not valid
indexing from: crawled to: out
index_load succeeded
index_save succeeded
Files out.sorted and check.sorted are identical
[paolo@flume ~/cs50/labs/tse/indexer]$
