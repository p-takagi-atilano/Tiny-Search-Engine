# Indexer Testing.md
## Paolo Takagi-Atilano

### running queriertest.sh
<code> [paolo@flume ~/cs50/labs/tse/querier]$ queriertest.sh
make: Entering directory '/net/tahoe3/paolo/cs50/labs/tse'
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
make[1]: Entering directory '/net/tahoe3/paolo/cs50/labs/tse/querier'
rm -f *~ *.o *.dSYM
rm -f querier
make[1]: Leaving directory '/net/tahoe3/paolo/cs50/labs/tse/querier'
make: Leaving directory '/net/tahoe3/paolo/cs50/labs/tse'
make: Entering directory '/net/tahoe3/paolo/cs50/labs/tse'
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
make[1]: Entering directory '/net/tahoe3/paolo/cs50/labs/tse/querier'
gcc -Wall -pedantic -std=gnu11 -ggdb -I../libcs50 -I../common   -c -o querier.o querier.c
gcc -Wall -pedantic -std=gnu11 -ggdb -I../libcs50 -I../common querier.o ../common/common.a ../libcs50/libcs50.a -o querier
gcc -Wall -pedantic -std=gnu11 -ggdb -I../libcs50 -I../common   -c -o fuzzquery.o fuzzquery.c
gcc -Wall -pedantic -std=gnu11 -ggdb -I../libcs50 -I../common fuzzquery.o ../libcs50/libcs50.a -o fuzzquery
make[1]: Leaving directory '/net/tahoe3/paolo/cs50/labs/tse/querier'
make: Leaving directory '/net/tahoe3/paolo/cs50/labs/tse' </code>

### crawling and indexing
<code> mkdir: cannot create directory ‘crawled’: File exists
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
indexing from: crawled to: out </code>

### fuzztesting:
<code> ./fuzzquery: generating 1000 queries from 6506 words
KEY WORDs:> Query: nearby and cms 
No documents match.
KEY WORDs:> Query: lost or downhill gerry or principles duffy 
Matches 2 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: netherlands diapers or mandriva 
Matches 1 documents (ranked):
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: startups or shipler parallel edifice and binomial or until 
Matches 5 documents (ranked):
score   4 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   3 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   3 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   3 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: demonstrates pottery mathematical since or tsch 
Matches 1 documents (ranked):
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: anjuta 
Matches 1 documents (ranked):
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: finite supported or work 
Matches 6 documents (ranked):
score   3 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   2 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   2 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   2 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   2 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: door 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: robotics or easily or complicate and schulberg and ieee 
Matches 4 documents (ranked):
score   5 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   2 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   2 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: upbearer thanasis domestic 
No documents match.
KEY WORDs:> Query: internships and until objective or reasonable guelph 
No documents match.
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: carnages or treating chained encoded greennews or quality 
Matches 6 documents (ranked):
score   2 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   2 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: aneurysms or given terces or mark or spell 
Matches 5 documents (ranked):
score   2 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   2 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: doubled 
Matches 1 documents (ranked):
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: memory or rock 
Matches 6 documents (ranked):
score  31 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score  23 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score  15 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   5 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   3 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: badenhausen or saturday and actions 
Matches 1 documents (ranked):
score   2 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: goals or overexcitements or bob and chirimen or mouse such 
Matches 2 documents (ranked):
score   2 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: directory wrought nading heroes spagyric 
No documents match.
KEY WORDs:> Query: you or whitespace or miami or guided and shippage 
Matches 6 documents (ranked):
score   8 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score   4 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   4 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   3 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   2 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   2 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: consequently and aix 
Matches 1 documents (ranked):
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: xenix impecuniously repeatedly or algebra and miss 
Matches 1 documents (ranked):
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: randell intel or manner or check colmar builtins 
Matches 2 documents (ranked):
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: existentialize tenure collegiate interval 
No documents match.
KEY WORDs:> Query: backwards 
Matches 1 documents (ranked):
score   2 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: participate and placing or generation and adoption 
Matches 2 documents (ranked):
score   2 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: trustee 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: intercolumnation or showtoplink handling or drosophilidae 
Matches 2 documents (ranked):
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: connectivity or money kemeny or sharealike preceded pseudo 
Matches 2 documents (ranked):
score   2 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: unixware or lesson or game 
Matches 2 documents (ranked):
score   2 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: manuel bellwort and catalog 
No documents match.
KEY WORDs:> Query: bowler cognition 
No documents match.
KEY WORDs:> Query: ole last agree 
Matches 1 documents (ranked):
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: binstock and presented or enabled and bituminizing moved primary 
No documents match.
KEY WORDs:> Query: changedness since letter or software reorganization 
No documents match.
KEY WORDs:> Query: sections 
Matches 2 documents (ranked):
score   2 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: samuel concern and looping 
No documents match.
KEY WORDs:> Query: padres herman vendor citation mugweed sublunated 
No documents match.
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: according or unbridged and denounces or tournament 
Matches 5 documents (ranked):
score   4 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   3 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   3 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: browser lookup gives or literature or computable or bronze 
Matches 2 documents (ranked):
score   3 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   2 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: varsity 
Matches 1 documents (ranked):
score   8 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: technique and automatically interchangeability or finance 
Matches 1 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: workstation maybe and center or userland and dee 
No documents match.
KEY WORDs:> Query: lettering or net 
Matches 3 documents (ranked):
score   4 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   2 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   2 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: requested 
Matches 1 documents (ranked):
score   2 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: bionic muns 
No documents match.
KEY WORDs:> Query: engine cleuk did 
No documents match.
KEY WORDs:> Query: methods boudreaux casually squamosoimbricated marye and rest 
No documents match.
KEY WORDs:> Query: yes 
Matches 1 documents (ranked):
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: fitzgerald or princeton 
Matches 2 documents (ranked):
score  11 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: angel and uppsala 
No documents match.
KEY WORDs:> Query: wasting 
Matches 1 documents (ranked):
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: directions ajax necessary lietuvi or recordings 
Matches 3 documents (ranked):
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: mohegan or invalidating grows bicentennial or hart 
Matches 1 documents (ranked):
score   2 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: arnold or versa or thornton phillips and varl or coed 
Matches 2 documents (ranked):
score   4 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: publicly or without or life agnew textual and sices 
Matches 6 documents (ranked):
score   8 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score   6 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   2 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   2 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   2 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: piper and contributors 
No documents match.
KEY WORDs:> Query: hillculture deleting and about combine 
No documents match.
KEY WORDs:> Query: char 
Matches 1 documents (ranked):
score   4 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: multipresence 
No documents match.
KEY WORDs:> Query: carnegie portably and utilisation and eace or ascc or inability 
Matches 2 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: reset and banquo keggy converge 
No documents match.
KEY WORDs:> Query: talg special and enum spire unmaintained or persist 
Matches 1 documents (ranked):
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: gerry especially 
No documents match.
KEY WORDs:> Query: logical scientists 
Matches 1 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: tyler off running or pushed 
Matches 1 documents (ranked):
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: emory or revolution reshaping and francisco 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: manuel or preserving groups richardson 
Matches 2 documents (ranked):
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: accomplishes opportunities 
No documents match.
KEY WORDs:> Query: paste or louis 
Matches 3 documents (ranked):
score   2 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: treat or returned ellis and converting 
Matches 2 documents (ranked):
score   3 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: cannophori or parsleywort and possible 
No documents match.
KEY WORDs:> Query: underwent or frederick whatever compile 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: missionary imperative lyme 
No documents match.
KEY WORDs:> Query: kind task or bokm sports 
Matches 4 documents (ranked):
score   2 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: allocators or wgrelevantpagename whites matriarchate efreet 
Matches 1 documents (ranked):
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: independently governor 
No documents match.
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: nunhood fellowships or winter or furlan or quite 
Matches 4 documents (ranked):
score  10 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   2 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   2 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   2 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: tuition 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: produces and trial 
No documents match.
KEY WORDs:> Query: cytococci theodore clarkson carriage or funders or frat 
Matches 1 documents (ranked):
score   2 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: load exchange genealogy zeros evaluative 
No documents match.
KEY WORDs:> Query: fifo colmar djave or drivers and caching domains 
No documents match.
KEY WORDs:> Query: tab 
Matches 1 documents (ranked):
score   2 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: museum and exists or data or occupied categorical supplied 
Matches 6 documents (ranked):
score  94 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score  34 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score  26 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score  26 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   3 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: requests speakers brezhoneg sites and posing 
No documents match.
KEY WORDs:> Query: pharmaceutical dramatically technical 
No documents match.
KEY WORDs:> Query: finally precise students 
No documents match.
KEY WORDs:> Query: unlogged robin and scrawniest theory or nanometer people 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: iconic or dummy or practice 
Matches 6 documents (ranked):
score   3 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score   3 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   2 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   2 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   2 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: unburned or irradiate or independently lawsuit allow 
Matches 1 documents (ranked):
score   2 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: vita or compact 
Matches 2 documents (ranked):
score   4 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: skyrocketing appropriate popularity each or convention gracefully 
No documents match.
KEY WORDs:> Query: declined players and disparity ebenezer 
No documents match.
KEY WORDs:> Query: rhodophane or initialized 
Matches 1 documents (ranked):
score   3 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: disappearing and form 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: hiding 
Matches 1 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: its subacetate or polygraphist or whetter 
No documents match.
KEY WORDs:> Query: hydraulist rago solving antiquity prominent or watchlisthideown 
Matches 6 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: fall corrupt or ayisyen 
Matches 1 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: sizes lpr 
No documents match.
KEY WORDs:> Query: auditioned and site nndb 
No documents match.
KEY WORDs:> Query: might or rumagn or workbench once 
Matches 4 documents (ranked):
score   3 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   2 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   2 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: calcimine or cameras gain or exchange or theofanis or kdevelop 
Matches 3 documents (ranked):
score   2 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   2 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: lazybed flailing or mathematical formulated and optimization or wgulscurrentautonym 
Matches 6 documents (ranked):
score   2 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: without resolved goffstown expects and regarded and acm 
No documents match.
KEY WORDs:> Query: inactivate or hacker 
Matches 1 documents (ranked):
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: friedman or convinced and therefore july multiset or grandparents 
Matches 2 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: wally lutaceous or championship 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: harassment 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: majority falsely or originist pointers attorney or nearest 
Matches 1 documents (ranked):
score   2 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: creative distributed 
Matches 3 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: paradigms interfaces or around and collections or freely 
Matches 5 documents (ranked):
score   3 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   2 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: mandate 
Matches 1 documents (ranked):
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: animals or interactive or pier 
Matches 4 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: editor and sandra sphenotribe 
No documents match.
KEY WORDs:> Query: demise or ceremony or categories 
Matches 6 documents (ranked):
score   4 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   4 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   2 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   2 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   2 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   2 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: encompasses frysk akerman 
No documents match.
KEY WORDs:> Query: restrict inherent and category or untagged citing dreyfusard 
Matches 1 documents (ranked):
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: utilisation reliability policy crinital or prevent 
Matches 1 documents (ranked):
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: name 
Matches 6 documents (ranked):
score   8 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   4 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   4 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   4 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score   3 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   2 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: snookers and testing or dangerous and athens 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: yields statesmanese 
No documents match.
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: insufficient nonetheless 
No documents match.
KEY WORDs:> Error: bad character '.' in query.
KEY WORDs:> Query: wgmonthnamesshort or others postedit or studying and constant 
Matches 6 documents (ranked):
score   2 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   2 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   2 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   2 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: safe brain and exchange and topuniversities 
No documents match.
KEY WORDs:> Query: harassment or pour institute unsuccessful bring 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: athletics bandjermasin or umpirages or tippled lead caleb 
No documents match.
KEY WORDs:> Query: gonimolobe 
No documents match.
KEY WORDs:> Query: specifically mustee 
No documents match.
KEY WORDs:> Query: treated or hanses and your or nytimes 
Matches 3 documents (ranked):
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: gone keynote or material and usa invariables 
No documents match.
KEY WORDs:> Query: arrangement and enabled or identifying and formed outpurse 
Matches 1 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: rolling internationals assumptions 
No documents match.
KEY WORDs:> Query: manipulated mcgraw rollouts congress 
No documents match.
KEY WORDs:> Query: croatia or katie 
Matches 1 documents (ranked):
score   3 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: mclaughlin and cathartically 
No documents match.
KEY WORDs:> Query: integration 
Matches 1 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: specializes 
Matches 1 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: corresponds recompete 
No documents match.
KEY WORDs:> Query: smallest or technostress freeing 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: obtaining and lynah flea issn 
No documents match.
KEY WORDs:> Query: subfields or alleluiatic levenez santo 
Matches 1 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: inhalational discretion or equestrian 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: exited note 
No documents match.
KEY WORDs:> Query: admission or children or devised or enchantress or misplaced princeton 
Matches 3 documents (ranked):
score   4 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   2 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: loukides or ucr details and facade 
Matches 1 documents (ranked):
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: whilst heterogeneity agenda 
No documents match.
KEY WORDs:> Query: modularity or midnight acoustical 
Matches 2 documents (ranked):
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: image forebespeak 
No documents match.
KEY WORDs:> Query: industrial consists italiano minahassa 
No documents match.
KEY WORDs:> Query: domain codebreakers or identifiers or wiley and asterionella or smalltalk 
Matches 2 documents (ranked):
score   7 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: themselves 
Matches 5 documents (ranked):
score   3 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   3 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: ancestor or ashworth toggles eastern francis 
Matches 1 documents (ranked):
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: homocercy or burgs quittance and mcp or deductive mountable 
No documents match.
KEY WORDs:> Query: relies core or weasel and depend or wwii 
Matches 1 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: relationships or tomahawks 
Matches 1 documents (ranked):
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: moving or impossible storytellings and party 
Matches 2 documents (ranked):
score   2 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: spread or datastructures 
Matches 2 documents (ranked):
score   2 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: martyrize rand thaumaturgism cpython 
No documents match.
KEY WORDs:> Query: lebanon 
Matches 1 documents (ranked):
score   2 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: believer apply anglo or aardvark or drawbacks 
Matches 1 documents (ranked):
score   2 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: useful 
Matches 4 documents (ranked):
score   6 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   4 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   3 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: automatica owner or consistency 
Matches 2 documents (ranked):
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: availability mathematically mandatory or hill 
Matches 4 documents (ranked):
score   3 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   2 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: freeman 
Matches 1 documents (ranked):
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: aestethic crc or touch and center rust 
No documents match.
KEY WORDs:> Query: allocations and winaray wizard 
Matches 1 documents (ranked):
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: cms syntax competitors nonsequestered difficulty 
No documents match.
KEY WORDs:> Query: navigation and grant videos queues alumnus elect 
No documents match.
KEY WORDs:> Query: wormian and jan 
No documents match.
KEY WORDs:> Query: conform 
Matches 1 documents (ranked):
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: rudolph 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: curricula and introduction and adoption best freeware or host 
Matches 2 documents (ranked):
score   2 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   2 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: passion banchi 
No documents match.
KEY WORDs:> Query: listing valley or adiposities 
No documents match.
KEY WORDs:> Query: css or technique representatives 
Matches 6 documents (ranked):
score   2 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: hidesig or swapping maintain and permit campaign and quite 
Matches 6 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: innermost or connecticut and keep or oracle or justifying 
Matches 2 documents (ranked):
score   2 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: values and arguing lccn and bronze 
No documents match.
KEY WORDs:> Query: event state matches 
No documents match.
KEY WORDs:> Query: clifford mkfs or provide southern 
No documents match.
KEY WORDs:> Query: accord balanced concepts sig and thomson 
No documents match.
KEY WORDs:> Query: unoccupied unanswered distinguished and users decompositions 
No documents match.
KEY WORDs:> Query: sensibly or moreover context 
Matches 2 documents (ranked):
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: languages 
Matches 6 documents (ranked):
score  41 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score  15 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score   9 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   6 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   3 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: workalike underprizing 
No documents match.
KEY WORDs:> Query: premolder or nonstandard or over and boardroom 
Matches 2 documents (ranked):
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: gettering approach and proceeding 
No documents match.
KEY WORDs:> Query: happiest scribe operands pallioessexite 
No documents match.
KEY WORDs:> Query: besides saucier 
No documents match.
KEY WORDs:> Query: origin senior sardu and unsuccessful 
No documents match.
KEY WORDs:> Query: scandal plain necula 
No documents match.
KEY WORDs:> Query: polynomial task or weapon and bounded 
Matches 1 documents (ranked):
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: lawlis resonants checking decryption 
No documents match.
KEY WORDs:> Query: bsearch clifford or quotation experts 
Matches 1 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: header 
Matches 2 documents (ranked):
score   4 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   3 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: unintended 
Matches 1 documents (ranked):
score   3 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: heliac 
No documents match.
KEY WORDs:> Query: valley autoheterodyne or trustee srpski emptory 
No documents match.
KEY WORDs:> Query: indirection 
Matches 1 documents (ranked):
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: simon matariki invigorations katharine and artificial 
No documents match.
KEY WORDs:> Query: manifested 
No documents match.
KEY WORDs:> Query: frequent remains 
No documents match.
KEY WORDs:> Query: purposes unicode and nature or functions arank 
Matches 1 documents (ranked):
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: squaws myers 
No documents match.
KEY WORDs:> Query: budd 
Matches 1 documents (ranked):
score   4 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: tat or keywords crowd 
No documents match.
KEY WORDs:> Query: allocators 
Matches 1 documents (ranked):
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: wheelock or kaiserdom lack deleted 
Matches 1 documents (ranked):
score  22 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: wild experienced 
No documents match.
KEY WORDs:> Query: popularity wgusername 
Matches 2 documents (ranked):
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: acoustical bomb or autokinetic or rolfe lacks 
No documents match.
KEY WORDs:> Query: uselivepreview commonly or usable or occupy deductive 
Matches 5 documents (ranked):
score   2 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: kartings manchester 
No documents match.
KEY WORDs:> Query: nonregistration 
No documents match.
KEY WORDs:> Query: gracefully withdrew or dartmuthensis hasbro or mossing mzn 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: speed folkishness and funded 
No documents match.
KEY WORDs:> Query: syriac and diego 
No documents match.
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: disablemail and its 
Matches 6 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: tune modules doctorate preserving and departments and pulsatilla 
No documents match.
KEY WORDs:> Query: bertrand or net immaterialness 
Matches 1 documents (ranked):
score   2 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: punched and speaking 
No documents match.
KEY WORDs:> Query: crosslets workbench or represented 
Matches 4 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: yamashita creating or papandreou or hobey 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: watchlisthideanons and minimize or omitted urethrograph and humans whereis 
Matches 2 documents (ranked):
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: cache backwards and macarthur and datalogy or internationals 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: cue nanometer or apogon saxapahaw or resource 
Matches 2 documents (ranked):
score   2 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: tigerflower pliroforiki platform hygrogram prophet 
No documents match.
KEY WORDs:> Query: summarize 
Matches 1 documents (ranked):
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: worked 
Matches 1 documents (ranked):
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: proctoscopic and machine msvc 
No documents match.
KEY WORDs:> Query: vaticanization ratified and translations or diagnostic or rabbi and reflects 
Matches 1 documents (ranked):
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: suites whatiscs sockeroos and technorealism million 
No documents match.
KEY WORDs:> Query: sarcophaguses theology gold point or publishing poonce 
No documents match.
KEY WORDs:> Query: amynodon 
No documents match.
KEY WORDs:> Query: subjectiveness endorsor subfields or svenska rewrite 
Matches 1 documents (ranked):
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: hacker or workstation about 
Matches 2 documents (ranked):
score   2 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: saurians verb erring continuation 
No documents match.
KEY WORDs:> Query: fortran or instructors and embedded straight incorporated and delaware 
Matches 2 documents (ranked):
score   4 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: circuits 
Matches 1 documents (ranked):
score   2 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: implementation automation 
Matches 1 documents (ranked):
score   2 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: kemp 
Matches 1 documents (ranked):
score   2 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: thunderbird or factor or spadixes needleman and turning 
Matches 3 documents (ranked):
score  25 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   2 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: zeros or efficient 
Matches 5 documents (ranked):
score  12 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   8 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score   3 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   3 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   2 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: rand colmer or latga anthropomorphotheist or convenience 
Matches 1 documents (ranked):
score   2 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: material york theme scandal 
No documents match.
KEY WORDs:> Query: ncp usable 
No documents match.
KEY WORDs:> Query: updating eclipse or tombs and molality and characters or overjutting 
No documents match.
KEY WORDs:> Query: slangism 
No documents match.
KEY WORDs:> Query: proliferate or undertaken 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: interreligious or nesh 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: opelt and designing and wgflowtermsofuseedit and subscriptions or assigned 
Matches 2 documents (ranked):
score   4 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   2 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: landis or undigestable belgravian or carries and governed workers 
Matches 1 documents (ranked):
score   2 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: sub or accord graham fierce anorthopia and football 
Matches 2 documents (ranked):
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: accommodations colliding or made famous 
Matches 2 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: propagines or accommodations inclusion wolof 
No documents match.
KEY WORDs:> Query: voyageurs inopportuneness changes and reaching 
No documents match.
KEY WORDs:> Query: columbia telecommunication 
No documents match.
KEY WORDs:> Query: alternatives master dmy and jim or internet 
Matches 4 documents (ranked):
score   3 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   2 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: performance and sharpless mapping ioctl 
No documents match.
KEY WORDs:> Query: jacob 
No documents match.
KEY WORDs:> Query: killall encouraged tight and reliable 
No documents match.
KEY WORDs:> Query: based sublated leiserson or producer tennis bus 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: reissuable or endianness or andrews append carnival except 
Matches 1 documents (ranked):
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: emphasize dirname offset inroads or zarp hardware 
No documents match.
KEY WORDs:> Query: subobsolete or real and review or fitness or watchlisthideown notopterus 
Matches 5 documents (ranked):
score   3 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   3 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   3 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: bokm notion or gettingstarted dicentras steps 
Matches 1 documents (ranked):
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: championship jack or heapsort 
Matches 2 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: woodbury requests or preemptive misdistinguish 
No documents match.
KEY WORDs:> Query: wire 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: superficie or sabotage dangerous 
No documents match.
KEY WORDs:> Query: resulted skip and visualization implicit and loadable percent 
No documents match.
KEY WORDs:> Query: somewhat olympics or additional systems or purify or brownian 
Matches 6 documents (ranked):
score  11 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   6 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   3 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score   2 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: producer country or solaris plain 
Matches 2 documents (ranked):
score   2 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: target 
Matches 2 documents (ranked):
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: mathematically or george synonymous redeeming and demisemitone or fourth 
Matches 2 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: binstock and fruithurst decision unfork come suavify 
No documents match.
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: wgrestrictionmove and jarvey or libraries and missorts or complicate 
Matches 1 documents (ranked):
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: edwin recovering 
No documents match.
KEY WORDs:> Query: browallia together cms animals or vincent perfect 
No documents match.
KEY WORDs:> Query: auxiliary basic or saktism uyghurche or pristine accessed 
Matches 4 documents (ranked):
score   2 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: streak or prisoner or lon or conferences and taikyu 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: limbo claude practices and contrast or navy 
Matches 1 documents (ranked):
score   3 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: coeducational or probing 
Matches 2 documents (ranked):
score  11 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   4 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: parallel leap freeware and hypologist or nostradamus or congregational 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: syntax or tying brent and speak 
Matches 3 documents (ranked):
score  15 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   2 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: tinselry else and diff cakile or avoids 
Matches 1 documents (ranked):
score   2 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: grim donated and auditing and ceos and boarisch 
No documents match.
KEY WORDs:> Query: descendants 
Matches 1 documents (ranked):
score   2 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: cose resize dedication or wgpagecontentmodel 
Matches 6 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: consultancy appointed and april 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: ancestor or predictive sue odf diddest 
Matches 1 documents (ranked):
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: kernighan amid crystallize comit efficiently 
No documents match.
KEY WORDs:> Query: select and costs or fifo or dullify 
Matches 1 documents (ranked):
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: summarize and weimer amble 
No documents match.
KEY WORDs:> Query: cleaners built hamingja goto or emissions second 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: awk or catherine banahan 
Matches 3 documents (ranked):
score   2 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: utility conversely and practices broonzy 
No documents match.
KEY WORDs:> Query: clay occom rehashing 
No documents match.
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: editsectiononrightclick pseudo tandem and dos and effectively telegraph 
No documents match.
KEY WORDs:> Query: slenderness or direct 
Matches 2 documents (ranked):
score   2 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: style and hiding 
Matches 1 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: brassiest yields infamed or scrutiny transhumanism and universal 
No documents match.
KEY WORDs:> Query: lemonias 
No documents match.
KEY WORDs:> Query: lymphopathy or addison and cerule and poltroonism 
No documents match.
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: overall and pike and dictionary wars or cats 
Matches 1 documents (ranked):
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: thanasis lists 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: messaging meinel and spaceflight oxford 
No documents match.
KEY WORDs:> Query: printable 
Matches 6 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: hit or compiler phiona or officer and accidentally esperanto 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: nikolas graduates combined regardless or drive 
Matches 1 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: instant or bibulously or phanerogenetic 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Error: bad character '.' in query.
KEY WORDs:> Query: turning multimap or heidi 
Matches 2 documents (ranked):
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: tell 
Matches 1 documents (ranked):
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: technoetic poll or specifiers bicarbonate lifetime 
No documents match.
KEY WORDs:> Query: electronic or hooker 
Matches 2 documents (ranked):
score   6 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   2 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: isonymy changed or telescopes and mckenzie or rewritten 
Matches 2 documents (ranked):
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: assigning thompson and package or arise 
Matches 1 documents (ranked):
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: structured couthly 
No documents match.
KEY WORDs:> Query: reservation linuxfocus implies 
No documents match.
KEY WORDs:> Query: externalised or licenses nonstandard latvie or drawbacks and contributing 
Matches 1 documents (ranked):
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: walpurgite or uprises 
No documents match.
KEY WORDs:> Query: thin and grant 
No documents match.
KEY WORDs:> Query: paste or nest and problems real literal scholarly 
Matches 1 documents (ranked):
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: revisory 
No documents match.
KEY WORDs:> Query: fibonacci enclosed or resilia 
No documents match.
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: opensuse or stridor or reasonably or november and richard and bounded 
Matches 2 documents (ranked):
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: hot and film implementing or graham even 
Matches 1 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: consonantising nyctitropism blemishes 
No documents match.
KEY WORDs:> Query: openvms emergence grants or disputes reduces or cells 
Matches 2 documents (ranked):
score   5 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score   3 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: sophisticated sorted became 
No documents match.
KEY WORDs:> Query: ghods and course attribute indoor and woodshop and mechanic 
No documents match.
KEY WORDs:> Query: increase or ghostscript or leeuwen indirectly unit 
Matches 4 documents (ranked):
score   4 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   2 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: release or wikibits or lebow permitting or unfulminant 
Matches 6 documents (ranked):
score   7 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   5 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   3 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   2 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   2 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   2 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: secretin or talg admits phonograph forceeditsummary or junonian 
No documents match.
KEY WORDs:> Query: emphasize durability or choultries desiring adapted 
No documents match.
KEY WORDs:> Query: interrupt or reimplant or interchangeability funded dermography 
Matches 2 documents (ranked):
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: uselivepreview essential and march gallantness and utilities or turn 
Matches 3 documents (ranked):
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: concluded or questions or implements bureau anti and practical 
Matches 3 documents (ranked):
score   3 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: delays 
Matches 1 documents (ranked):
score   2 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: area or wgcanonicalnamespace invariables dubliners 
Matches 2 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: industrial blaise and card 
Matches 1 documents (ranked):
score   2 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: vendors pioneers 
No documents match.
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: higher 
Matches 4 documents (ranked):
score   7 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   2 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   2 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: friends 
Matches 1 documents (ranked):
score   3 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: imperial or informatique 
Matches 1 documents (ranked):
score   2 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: bob diddlies 
No documents match.
KEY WORDs:> Query: academia winner or caroline 
Matches 1 documents (ranked):
score   3 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: nullificator 
No documents match.
KEY WORDs:> Query: epiphanise window or studio and dietlibc nov 
Matches 1 documents (ranked):
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: mehta president mike 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: updated macarthur 
No documents match.
KEY WORDs:> Query: scandinavian propagation or iterates critique correctly and epidemics 
No documents match.
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: than timbered tatar 
No documents match.
KEY WORDs:> Query: instructions lions or unmoralize and detected or atkin 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: finger or annulosa or expensive or ahrens or keratomalacia 
Matches 2 documents (ranked):
score   4 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score   2 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: modifying precautions formulated 
No documents match.
KEY WORDs:> Query: strongly tokens heptagon 
No documents match.
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: heavily and splenalgia 
No documents match.
KEY WORDs:> Query: floatation and arm hypobenthos 
No documents match.
KEY WORDs:> Query: newspaper resequester payload write stream 
No documents match.
KEY WORDs:> Query: mysandbox or enotifminoredits 
Matches 6 documents (ranked):
score   2 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   2 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   2 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   2 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   2 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   2 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: administered absolute or ted syracuse and garifalia 
No documents match.
KEY WORDs:> Query: versa telecommunication bivittate 
No documents match.
KEY WORDs:> Query: phrases or teach or moor or robustness and ratified and simple 
Matches 3 documents (ranked):
score   4 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   4 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: excretes lwn 
No documents match.
KEY WORDs:> Query: institute and athletic performed or mint bator 
No documents match.
KEY WORDs:> Query: herman or unrelinquishing morphous 
Matches 1 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: protection 
Matches 2 documents (ranked):
score   3 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   2 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: hair spice rich and france or map woodward 
Matches 1 documents (ranked):
score   2 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: initial and mode ernest or freed imbarkation locally 
No documents match.
KEY WORDs:> Query: news or unexpectedly shaffer or nonnegligibility 
Matches 4 documents (ranked):
score  22 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   2 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: directly 
Matches 4 documents (ranked):
score   5 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score   4 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: bed and concepts council founded motorboat 
No documents match.
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: megascale aganippe 
No documents match.
KEY WORDs:> Query: occurrences staphyloangina centered swapping and open comp 
No documents match.
KEY WORDs:> Query: anchinoe 
No documents match.
KEY WORDs:> Query: seven allie patent or lexical 
Matches 2 documents (ranked):
score   3 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: middle ahriman and skricki live overlash and brands 
No documents match.
KEY WORDs:> Query: windows salpinx halves or adaptation 
Matches 1 documents (ranked):
score   2 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: katharine and iteration regarded gabriel 
No documents match.
KEY WORDs:> Query: meehan relationship 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: suasively 
No documents match.
KEY WORDs:> Query: addressing 
Matches 3 documents (ranked):
score  28 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: min complicate 
Matches 1 documents (ranked):
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: sized or influential mandate and uls 
Matches 2 documents (ranked):
score   2 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   2 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: sparsehash or theodore or transport 
Matches 3 documents (ranked):
score   3 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   2 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: endocrinologist or linking consubstantiationist likely resnicoff 
No documents match.
KEY WORDs:> Query: geisel or hiland fewer manual 
Matches 1 documents (ranked):
score   5 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: blackberry mining canthal levi elaborator and odontaspis 
No documents match.
KEY WORDs:> Query: ls or valmy www western and angriest 
No documents match.
KEY WORDs:> Query: hashed subexpression or espn or ruby 
Matches 3 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: contains or declarative or oldest newsmaker and mail 
Matches 5 documents (ranked):
score  10 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score   6 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   4 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   2 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: object entering 
Matches 1 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: shemaal sized subset or suitable or arab 
Matches 6 documents (ranked):
score   2 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: red or stuart doubles and accommodated respectively 
Matches 4 documents (ranked):
score   3 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score   3 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: unanimate or print habit or flaunters or array demonstration 
Matches 1 documents (ranked):
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: nonurban and affirming or anthropophuistic displace or tinker and wiley 
No documents match.
KEY WORDs:> Query: chetan seminar or prophesying or shred 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: levi gaelg 
No documents match.
KEY WORDs:> Query: ssh 
Matches 1 documents (ranked):
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: permit or transactions historic 
Matches 1 documents (ranked):
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: ohio schultz or abelson and unavoidable and septifragally tomboyish 
No documents match.
KEY WORDs:> Query: pipes or device 
Matches 1 documents (ranked):
score   9 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: unices or melanoderm and untenuousness or internal 
Matches 4 documents (ranked):
score  13 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score   3 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: fayalites 
No documents match.
KEY WORDs:> Query: literal schedules 
No documents match.
KEY WORDs:> Query: similarly 
Matches 1 documents (ranked):
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: assumed 
Matches 1 documents (ranked):
score   2 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: divide lacks 
No documents match.
KEY WORDs:> Query: dishonor or citeseer or nyregion allison 
Matches 2 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: expense respectively 
No documents match.
KEY WORDs:> Query: chaos unpejorative sourcebook 
No documents match.
KEY WORDs:> Query: method pools or subterpose 
Matches 1 documents (ranked):
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: clintonite 
No documents match.
KEY WORDs:> Query: english graham telecommunications express or roomward or imagine 
Matches 1 documents (ranked):
score   2 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: reliability literals 
No documents match.
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: wizards or repairability or serovaccine paper 
No documents match.
KEY WORDs:> Query: remain designates soon academies or priority or government 
Matches 4 documents (ranked):
score   4 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   2 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   2 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score   2 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: secondary 
Matches 2 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: conked warning or umask or ungrouped 
Matches 2 documents (ranked):
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: structured top discussion 
Matches 1 documents (ranked):
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: pedro bob algebra 
Matches 1 documents (ranked):
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: romanceish technocentrism 
No documents match.
KEY WORDs:> Query: covering status parsons and subscripts or babbage 
Matches 1 documents (ranked):
score   9 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: philosopher or surviver 
Matches 1 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: inform distinction or matti tudor 
Matches 1 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: abraham upon randell borland or uninstructive modulo 
No documents match.
KEY WORDs:> Query: named nov 
Matches 2 documents (ranked):
score   2 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: susank 
No documents match.
KEY WORDs:> Query: compilers or minify forpass 
Matches 3 documents (ranked):
score  22 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   2 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: consists fjelds danish and estimated establish 
No documents match.
KEY WORDs:> Query: blocking or bay or cottonweed rhizocarpean 
Matches 2 documents (ranked):
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: phrygian or economy reservation infuriating 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: edu log or louise machines 
Matches 4 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: hyperintellectualness transferred versions 
No documents match.
KEY WORDs:> Error: bad character '.' in query.
KEY WORDs:> Query: parsers 
Matches 1 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: srpskohrvatski and dijkstra and belauding usenewrc 
No documents match.
KEY WORDs:> Query: unanswered or its markets and signal 
Matches 1 documents (ranked):
score   2 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: skeat or chemiatric and filename 
No documents match.
KEY WORDs:> Query: wgcurrevisionid or persuitte and force shaddai dangerous or semicoagulated 
Matches 6 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: minix matlab 
No documents match.
KEY WORDs:> Query: glance or reagan identifiable or oclc or transitions and passion 
Matches 1 documents (ranked):
score   4 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: endowed endothelioid 
No documents match.
KEY WORDs:> Query: misreader 
No documents match.
KEY WORDs:> Query: disciplinary or aneurysms 
Matches 2 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: poromas guinean and innovations odium 
No documents match.
KEY WORDs:> Query: illusion 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: salaries or maintainable 
Matches 2 documents (ranked):
score   2 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: product or once 
Matches 5 documents (ranked):
score   3 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   2 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   2 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: rendered setting 
No documents match.
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: preserving 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: occurrences or late or drama or tss 
Matches 6 documents (ranked):
score   4 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   3 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   3 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   2 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: begin and sigil or acronym and summary and high 
Matches 1 documents (ranked):
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: third and productivity and elliot or physician or timeline 
Matches 4 documents (ranked):
score   2 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: panero or upne winner or haverford 
Matches 1 documents (ranked):
score   4 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: sectors kernoi or corporation or pool and evangelist or frequently 
Matches 3 documents (ranked):
score   3 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: diplomas offline subexpression followed or conflict gilbert 
No documents match.
KEY WORDs:> Query: exhibit or comparing valid and line 
Matches 2 documents (ranked):
score   2 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: hall 
Matches 5 documents (ranked):
score  16 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   5 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   3 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: atkin or outdoorsman 
Matches 1 documents (ranked):
score   2 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: roberto 
Matches 1 documents (ranked):
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: affiliations convert cd 
No documents match.
KEY WORDs:> Query: best and hyman or mechanisms or institution 
Matches 4 documents (ranked):
score  12 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   3 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   2 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: engarment haem 
No documents match.
KEY WORDs:> Query: person 
Matches 1 documents (ranked):
score   7 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: early 
Matches 5 documents (ranked):
score  11 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   5 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   4 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   3 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   2 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: extendwatchlist and lane 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: hashes 
Matches 1 documents (ranked):
score   3 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: alemannisch 
Matches 3 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: ichthyocephalous or exit portion or relatively 
Matches 4 documents (ranked):
score   4 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   3 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   2 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: ensures or triangle or ufc incremental 
Matches 3 documents (ranked):
score   2 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: fancysig attendant or roeneng 
Matches 1 documents (ranked):
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: resembles 
Matches 1 documents (ranked):
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: cannot continues customization calculated or contemporaries 
Matches 1 documents (ranked):
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: mttr operation predamn 
No documents match.
KEY WORDs:> Query: isn or boolean notre 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: indicate or supplied and impression 
Matches 3 documents (ranked):
score   4 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: trips or sorenesses and organized humor coal 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: plus or stated or llc retail or reserve or away 
Matches 4 documents (ranked):
score   3 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   2 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: versableness handy set 
No documents match.
KEY WORDs:> Query: wins 
Matches 2 documents (ranked):
score   3 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: besoul 
No documents match.
KEY WORDs:> Query: disapproves amend 
No documents match.
KEY WORDs:> Query: latina or env corinthes wikidata abstract 
Matches 4 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: appleton malaanonang duffy or gerstner 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: matlab or andrews 
Matches 2 documents (ranked):
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: graduating and ocw overlover or hacker lexical 
Matches 1 documents (ranked):
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: copied expressions magazine 
No documents match.
KEY WORDs:> Query: chm natives or preexecuting or http task 
Matches 6 documents (ranked):
score   3 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   2 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: mentioned 
Matches 1 documents (ranked):
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: psychics and prefertility evaluate or body or famnode and comer 
Matches 6 documents (ranked):
score   5 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: twittery 
No documents match.
KEY WORDs:> Query: come or suites landis or transferal aiding or residential 
Matches 4 documents (ranked):
score   8 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   2 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: expanding or apply skiway circle connected gnabble 
Matches 1 documents (ranked):
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: detection or own or libbed abuses 
Matches 5 documents (ranked):
score   3 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   3 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   3 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: wgs or wikibits 
Matches 6 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: derivative 
Matches 1 documents (ranked):
score   2 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: ends 
Matches 2 documents (ranked):
score   2 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: collapsiblenav valley or designer hashmap 
Matches 2 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: confiders or project derives or necessarily 
Matches 3 documents (ranked):
score   2 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: football distribution different adopted and people or doran 
Matches 1 documents (ranked):
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: inuktitut 
Matches 1 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: makes haverford or arranged or integrity or dirname or toolchain 
Matches 3 documents (ranked):
score   2 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   2 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: based or quadral cpython or publishing or parameter watchtoken 
Matches 6 documents (ranked):
score  12 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   7 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   5 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   5 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   2 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   2 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: extender tubestock 
No documents match.
KEY WORDs:> Query: tend sharpless wgcanonicalnamespace softball and duplicature 
No documents match.
KEY WORDs:> Query: quantification sitting 
No documents match.
KEY WORDs:> Query: anthem 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: needham feature 
No documents match.
KEY WORDs:> Query: slide voip or impairment deboite executable or peek 
Matches 1 documents (ranked):
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: said rural ghods preach or normally 
Matches 3 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: proteidean mwembedsupport 
No documents match.
KEY WORDs:> Query: subfield 
Matches 1 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: selected and clear universallanguageselector 
Matches 2 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: invalidating and kymograph or mischarge 
No documents match.
KEY WORDs:> Query: thank and arables or encoding prefer 
No documents match.
KEY WORDs:> Query: alternative or dartmouthsports and adts loew 
Matches 3 documents (ranked):
score   3 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: someone practical 
Matches 1 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: suggested asked or enchantress and tombs tokens 
No documents match.
KEY WORDs:> Query: threshold and bill or weaknesses sphinx explanation or epistemology 
Matches 1 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: kulesh age or bistable earn reversed 
Matches 1 documents (ranked):
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: detection or retail association signifies framework 
Matches 2 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: aggressive and inventing subcript 
No documents match.
KEY WORDs:> Query: pays ransomable bokm extends void 
No documents match.
KEY WORDs:> Query: innovations and cnn or mention transfer 
Matches 2 documents (ranked):
score   2 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: friday or auditing or finished 
Matches 3 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: mit founding 
Matches 2 documents (ranked):
score   2 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: rolling 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: cheney 
Matches 1 documents (ranked):
score   2 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: reallocation or frustrated or preprocessor engineers or degree revival 
Matches 4 documents (ranked):
score   3 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: internationalization optional gottfried basal 
No documents match.
KEY WORDs:> Query: genius and unupright winaray or created 
Matches 5 documents (ranked):
score   6 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   5 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score   2 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   2 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: accordance or culture or academics or sophomore 
Matches 2 documents (ranked):
score   9 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: dev and removing and player 
No documents match.
KEY WORDs:> Query: depravation and western or surveyed or simplified 
Matches 4 documents (ranked):
score   2 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: pyrochlore 
No documents match.
KEY WORDs:> Query: allocators and serpette 
No documents match.
KEY WORDs:> Query: groklaw or engineers athens or guidelines or predate 
Matches 4 documents (ranked):
score   3 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   3 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   2 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: distinction and pidof jordan mint and being or text 
Matches 6 documents (ranked):
score  14 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score  13 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score  11 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score  10 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   8 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   7 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: britannica editondblclick and nic and lead remlinger or saki 
No documents match.
KEY WORDs:> Query: lovelace music relisting and regarded 
No documents match.
KEY WORDs:> Query: mcleland misplaced 
No documents match.
KEY WORDs:> Query: entertainment and reading 
Matches 2 documents (ranked):
score   2 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   2 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: achievements or two or circumcolumnar includes or exploration or alignment 
Matches 6 documents (ranked):
score  25 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score  17 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score  14 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score  10 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   2 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   2 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: mamuneas deleting 
No documents match.
KEY WORDs:> Query: ilokano americans 
No documents match.
KEY WORDs:> Query: effect or kemp 
Matches 3 documents (ranked):
score   3 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   3 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: pcc and phacochere and programmers and another and million 
No documents match.
KEY WORDs:> Query: interlanguage owns enotifwatchlistpages 
Matches 2 documents (ranked):
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: tonguebird 
No documents match.
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: peddleress 
No documents match.
KEY WORDs:> Query: ingirt or fielded and carolina 
No documents match.
KEY WORDs:> Query: reasonable hidepatrolled 
Matches 1 documents (ranked):
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: opera develop colleagues 
No documents match.
KEY WORDs:> Query: gentoo and volume and sys and invoker or implications or subdirectories 
Matches 2 documents (ranked):
score   2 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: amember lapwings 
No documents match.
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: sociocultural or edictum candidates or pointing using 
Matches 2 documents (ranked):
score   5 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: broad hashing or room trustee spasmolytically 
No documents match.
KEY WORDs:> Query: enumeration and commands or neurotically or revival widespread circuit 
Matches 1 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: happens or programmers and broadcast or commission comments 
Matches 2 documents (ranked):
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: flop participate sustainable or css cluster and own 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: nabity 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: kauler or mclaughlin win and capotastos or larger and ureteropyelonephritis 
Matches 1 documents (ranked):
score   1 docID     1 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/
-----------------------------------------------
KEY WORDs:> Query: increasingly and address shadowily inventing 
No documents match.
KEY WORDs:> Query: mission 
Matches 1 documents (ranked):
score   2 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: against and whipple molleton 
No documents match.
KEY WORDs:> Query: croppie or trimorphism act or pools 
Matches 1 documents (ranked):
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: bachelor or smith making began 
Matches 1 documents (ranked):
score   4 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: included closes olshansky or specifically tim 
Matches 2 documents (ranked):
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: bochism or concern 
Matches 1 documents (ranked):
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: philosophical or microkernel 
Matches 2 documents (ranked):
score   3 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: well and tab and know 
Matches 1 documents (ranked):
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: journalism or brither 
Matches 2 documents (ranked):
score   2 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: wgpagecontentmodel or jumping architecture or operators and beryline and internally 
Matches 6 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: crystallize locality 
No documents match.
KEY WORDs:> Query: sparrygrass or seeking 
Matches 1 documents (ranked):
score   2 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: translate global 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: involves or mclaughlin and chaochowfu or finds 
Matches 4 documents (ranked):
score   3 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score   2 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: election or danish xavier 
Matches 2 documents (ranked):
score   2 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   2 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: shows opposed and pam controlled wallace 
No documents match.
KEY WORDs:> Query: silently viewpagetarget elect persevered argv moran 
No documents match.
KEY WORDs:> Query: dialyzability and indijbiously 
No documents match.
KEY WORDs:> Query: international and executive celebratory and wikilove 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: macdonald or christine or cellular included 
Matches 2 documents (ranked):
score   4 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: asymco 
Matches 1 documents (ranked):
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: meant and disruption and cpl 
No documents match.
KEY WORDs:> Query: documents 
Matches 3 documents (ranked):
score   2 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   2 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: chondropterygian or interface battle and sets action or rhyptical 
No documents match.
KEY WORDs:> Query: gettingstarted or denning sustainability 
Matches 6 documents (ranked):
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: postedit permanent languages prowler various convention 
No documents match.
KEY WORDs:> Query: dos 
Matches 1 documents (ranked):
score   2 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: reduce 
Matches 2 documents (ranked):
score   2 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: negative or santa or bilgewater 
Matches 2 documents (ranked):
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: roland and mediate 
No documents match.
KEY WORDs:> Query: drawing impolitical 
No documents match.
KEY WORDs:> Query: nuncupated tyler challenged despicable or mechatronics 
Matches 1 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: wasting 
Matches 1 documents (ranked):
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: orbiculares technoethics and seiterle 
No documents match.
KEY WORDs:> Query: interpaved grows or etc plackett 
Matches 1 documents (ranked):
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: maccabaeus store 
No documents match.
KEY WORDs:> Query: comp or pranceful middle lowest ken 
Matches 2 documents (ranked):
score   3 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: tamara 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: zend or unliveries take or retainership affirmed authoritative 
Matches 1 documents (ranked):
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: trt 
No documents match.
KEY WORDs:> Query: doctrinalist chapman loses 
No documents match.
KEY WORDs:> Query: tail casually detailed or additionally or learnership and galego 
Matches 1 documents (ranked):
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: irix or shaw or mdy pneumonomycosis 
Matches 3 documents (ranked):
score   3 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score   2 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: reasonably classical and lecture rivalize emphasise 
No documents match.
KEY WORDs:> Query: criterion and board draghound or oct or buildings 
Matches 6 documents (ranked):
score  19 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   2 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: bits or recruiting and mckenzie roberto 
Matches 6 documents (ranked):
score   3 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   2 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   2 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   2 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: indies or georges or blawed danger matt 
No documents match.
KEY WORDs:> Query: kind unmotivatedly or athens and bjarne begun or patterns 
Matches 2 documents (ranked):
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: minute 
Matches 1 documents (ranked):
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: evaluations and works gavra and orgastic and site 
No documents match.
KEY WORDs:> Query: hyman and existed eecs 
Matches 1 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: avoid or hope reflexologically csta 
Matches 5 documents (ranked):
score   4 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   3 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score   2 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   2 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: rudolph and bickleton bejelling 
No documents match.
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: any or all or alexandra 
Matches 6 documents (ranked):
score  40 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score  32 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score  31 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score  28 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score  20 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score  14 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: strengths and unrolled 
Matches 1 documents (ranked):
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: porcia proprietary touch argc base 
No documents match.
KEY WORDs:> Query: trend or face harbison or wild 
Matches 3 documents (ranked):
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: poorly 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: aziz 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: scripting or assessment fellowheirship and tours or advance stories 
Matches 2 documents (ranked):
score   3 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: pancreatogenic 
No documents match.
KEY WORDs:> Query: brandeis or jocant octoradiate cutinised 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: culture and cliffs or nature or yacc eric 
Matches 4 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: italian or pottery 
Matches 2 documents (ranked):
score   2 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: invoke ground mislear or wired lacks 
No documents match.
KEY WORDs:> Query: circuits and cgd reach 
No documents match.
KEY WORDs:> Query: contributing tidy and elsewhere or variadic vldb 
No documents match.
KEY WORDs:> Query: arr or supply or hierarchical or aims or traumatizes and conscious 
Matches 4 documents (ranked):
score   4 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   3 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   3 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: answer dodger or annunciate ice amaga 
No documents match.
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: internationals or napulitano convert and randy denote 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: interview research or emotionalistic and totems and emergence 
Matches 3 documents (ranked):
score   3 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   3 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: sub httrack unbettered or wllimit or consortium 
Matches 6 documents (ranked):
score   4 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   2 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: math or kurd and writhes or four out 
Matches 6 documents (ranked):
score   7 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   4 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   2 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   2 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: preremove 
No documents match.
KEY WORDs:> Query: organize or shorthand and surprises revenge geithner almice 
Matches 1 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: alumni 
Matches 1 documents (ranked):
score  39 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: grasshopperdom sherwin 
No documents match.
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: underscored 
Matches 1 documents (ranked):
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: tasks and microcomputers bionic and course 
No documents match.
KEY WORDs:> Query: competes or luhn or telephone jorgen uninitialized 
Matches 2 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: exceed and lexical appointed animation or unspecified 
Matches 2 documents (ranked):
score   2 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: vulnerable or stated and nix and donors 
Matches 1 documents (ranked):
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: mater 
Matches 1 documents (ranked):
score   4 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: user lcc 
Matches 1 documents (ranked):
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: methodist and uptime 
No documents match.
KEY WORDs:> Query: testing 
Matches 2 documents (ranked):
score   3 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   2 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: with and diskography or resolution 
Matches 1 documents (ranked):
score   5 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: nofollow infrequent floating accumulation neolithic and alef 
No documents match.
KEY WORDs:> Query: gentoo conservatoires roentgenological sherwin or electro 
Matches 1 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: acre moose and briefcase or right 
Matches 3 documents (ranked):
score   3 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   2 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   2 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: lengthy and feature and proprietary and trampers or smaller 
Matches 3 documents (ranked):
score   2 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   2 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: presently cumming or ranjan underpinning or rogers 
Matches 1 documents (ranked):
score   3 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: june and diagnostic dwight 
No documents match.
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: brimfully simon and valgrind pepticity 
No documents match.
KEY WORDs:> Query: coroutines 
Matches 1 documents (ranked):
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: circle or person or operating pennsylvania and shorthand or php 
Matches 6 documents (ranked):
score  15 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score   6 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   4 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   2 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: berrettas or iterative or apartment bay 
Matches 3 documents (ranked):
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: minnesota or intentively or fedoraproject weatherston srpskohrvatski or brunhild 
Matches 1 documents (ranked):
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: dragon and submitting into or robotic or stealths or applications 
Matches 5 documents (ranked):
score   8 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   7 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   6 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   5 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   4 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: methods remlinger 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: completely or gnitirw 
Matches 3 documents (ranked):
score   3 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: play and sex or ridgiest murray engineers and degrees 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: ordinary vertus or universit offer or virtually 
Matches 1 documents (ranked):
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: sculpture or nil or rented and simple 
Matches 2 documents (ranked):
score   2 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: nanoengineering saturday sentinels maudie and robustness 
No documents match.
KEY WORDs:> Query: suitable or stephen continue or producer abet macrofossil 
Matches 3 documents (ranked):
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: silkweeds and comity and disjoint 
No documents match.
KEY WORDs:> Query: allowed and windowing 
No documents match.
KEY WORDs:> Query: focaloid frequency or there 
Matches 6 documents (ranked):
score  14 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score  14 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   8 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   4 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: talk agreed soon 
Matches 1 documents (ranked):
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: clearly and biology nautiluses 
No documents match.
KEY WORDs:> Query: gets and catalog binary or elf 
Matches 2 documents (ranked):
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: matti wgrevisionid burton worded profit inexactitude 
No documents match.
KEY WORDs:> Query: dartmuthensis and sys and variation developments or compete 
Matches 1 documents (ranked):
score   2 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: updating or desiring flaggedrevsviewdiffs play initiated antithetic 
Matches 1 documents (ranked):
score   3 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: herdswoman 
No documents match.
KEY WORDs:> Query: withdrew or preparation or shaddai or vacuum wyck and pyrrol 
Matches 2 documents (ranked):
score   2 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   2 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: perez wgpagecontentlanguage deutsch 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: definitions marechale or santo involves kemi 
No documents match.
KEY WORDs:> Query: adversary 
Matches 1 documents (ranked):
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: amsterdam or hemmendinger quiet 
Matches 1 documents (ranked):
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: miles criterion and ago and jessica or announces multimap 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: villagery sequent nanoengineering partially 
No documents match.
KEY WORDs:> Query: primarily or study or plymouth and iii best 
Matches 4 documents (ranked):
score  20 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   8 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: avourneen kauler cecostomy 
No documents match.
KEY WORDs:> Query: tagalog 
Matches 2 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: top 
Matches 5 documents (ranked):
score   7 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: character 
Matches 3 documents (ranked):
score  14 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: woodbury dates intended persist ken 
No documents match.
KEY WORDs:> Query: poluphloisboic 
No documents match.
KEY WORDs:> Query: tsl unified and priorities removeafter or allowing 
Matches 2 documents (ranked):
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: legends or gold xiphydriid or wgcategorytreepagecategoryoptions noncrossover and delegated 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: milieu and bureau characterization and skiing refers and cinderella 
No documents match.
KEY WORDs:> Query: brand 
Matches 2 documents (ranked):
score   2 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: achieved deserve approaches adam interrupt initiated 
No documents match.
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: misdefining swellest follow technoself 
No documents match.
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: degrees existing cal marker or biology 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: eisb or academy connect professional promotional cfd 
No documents match.
KEY WORDs:> Query: flooring wgrestrictionmove or observer count indices 
No documents match.
KEY WORDs:> Query: living boomeranged and rand annals 
No documents match.
KEY WORDs:> Query: develops and boudreaux estimated 
No documents match.
KEY WORDs:> Query: recovered or sequential consider something animals confutative 
Matches 1 documents (ranked):
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: channel riksdaalder or interleaves stallman or wgisprobablyeditable 
Matches 6 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: stubthreshold contribute and your 
Matches 1 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: trustee and mysandbox or through 
Matches 5 documents (ranked):
score   8 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score   4 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   3 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   2 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   2 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: debonis 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: map and bernard and diverts entirely 
No documents match.
KEY WORDs:> Query: gemitorial or telecommunication archings or somenode bloodstock or amounts 
Matches 1 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: indoor and program config 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: grid or criterion 
Matches 3 documents (ranked):
score   2 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: offered 
Matches 1 documents (ranked):
score   2 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: zeros and supersized passes and lastname 
No documents match.
KEY WORDs:> Query: dialects 
Matches 1 documents (ranked):
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: clear and symposium fix 
Matches 1 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: netherlands 
Matches 1 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: hukbalahap managing linebacker 
No documents match.
KEY WORDs:> Query: championship hideprefix describing attend modernization 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: halves or shotmaker 
Matches 1 documents (ranked):
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: brands or act rowing and adrenergic 
Matches 1 documents (ranked):
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: here has duke mary or mpe 
Matches 2 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: paddock or cpython sponsored unchanged or dougherty or advertising 
Matches 2 documents (ranked):
score   2 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: whether or shipside subjectibility releasing or coherent 
Matches 6 documents (ranked):
score   3 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   2 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: debugging 
Matches 1 documents (ranked):
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: necessarily inventing and scots and matster abraham or dealfishes 
No documents match.
KEY WORDs:> Query: variolating 
No documents match.
KEY WORDs:> Query: making morse 
Matches 1 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: positives rented and buffalo separate 
No documents match.
KEY WORDs:> Query: experimental fringetail rage 
No documents match.
KEY WORDs:> Query: complex or sorosil saucier 
Matches 5 documents (ranked):
score   5 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   4 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: wgisprobablyeditable 
Matches 6 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: beilul 
No documents match.
KEY WORDs:> Query: horton internal or implementations and protends addresses viewpagetarget 
No documents match.
KEY WORDs:> Query: col topology informatica 
No documents match.
KEY WORDs:> Query: bulkdelcourses louis occupied bound or julian limit 
Matches 1 documents (ranked):
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: mean design or auto and prohibitively 
Matches 2 documents (ranked):
score   2 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: disembowelments examples 
No documents match.
KEY WORDs:> Query: success or gym readable 
Matches 2 documents (ranked):
score   4 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: publicly or chaco senior 
Matches 1 documents (ranked):
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: figure and const or clasher or suffer 
Matches 1 documents (ranked):
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: royalties latvie thin 
No documents match.
KEY WORDs:> Query: fusion or included and sip 
Matches 2 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: dickey backwards boathouse 
No documents match.
KEY WORDs:> Query: fit quinnipiac bell 
No documents match.
KEY WORDs:> Query: transport 
Matches 1 documents (ranked):
score   2 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: randell emball 
No documents match.
KEY WORDs:> Query: him or bobcats uniq residential and ralph 
Matches 1 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: dijkstra or oclc and containing 
Matches 2 documents (ranked):
score   3 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: results and nesslerised unlofty 
No documents match.
KEY WORDs:> Query: hemimetabole idea and bamileke colp or github 
Matches 1 documents (ranked):
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: calculated or month emilio 
Matches 2 documents (ranked):
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: journalist or became or torulae cyclone infected 
Matches 4 documents (ranked):
score   6 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   5 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   5 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: trademarked or interdisciplinary 
Matches 2 documents (ranked):
score   2 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: gilbert 
Matches 1 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: folding and origins or emmy newnode 
Matches 1 documents (ranked):
score   2 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: million or parenthesized majority and teach and foetiparous or prolapsing 
Matches 2 documents (ranked):
score   4 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: potential popularity 
No documents match.
KEY WORDs:> Query: planning spreading and laws ihsa and lds or wgcoordinates 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: electronic gradually pxe ramistical or patinate prefers 
No documents match.
KEY WORDs:> Query: irix and protest or wikisource or several duplicate or huntington 
Matches 3 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: devise leadoffs 
No documents match.
KEY WORDs:> Query: whitaker or dedicated or visible or discovers task assume 
Matches 3 documents (ranked):
score   3 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: august 
Matches 6 documents (ranked):
score 151 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   4 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   3 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   3 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: select zayins yard and manager 
No documents match.
KEY WORDs:> Query: arteriasis and consisting or fighter linkable or explicitly rechecked 
No documents match.
KEY WORDs:> Query: devoted or woodward and unmysticize 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: ubiquitous lardier engraved and exit stanford norsk 
No documents match.
KEY WORDs:> Query: cumic or steph 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: popularity or gras posix coso haldeman checked 
Matches 2 documents (ranked):
score   3 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: capmakers or minute crowd and collins takes or expertise 
Matches 1 documents (ranked):
score   2 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: anthony down or lafayette 
Matches 1 documents (ranked):
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: mathematical 
Matches 3 documents (ranked):
score  11 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: addition nebalioid or matarikinetwork and mudcap and developmental or templates 
Matches 6 documents (ranked):
score   5 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score   3 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   3 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   3 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   3 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   2 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: potentially or nic delightful content or neuroscience unniggard 
Matches 3 documents (ranked):
score   4 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   3 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: letters and delaware argiopidae type periodically invention 
No documents match.
KEY WORDs:> Query: dialectical and wxdev departments or animation nil and rage 
No documents match.
KEY WORDs:> Query: expeditionist 
No documents match.
KEY WORDs:> Query: requirement testiculate connery isolated 
No documents match.
KEY WORDs:> Query: point microcontrollers 
Matches 1 documents (ranked):
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: lint 
Matches 1 documents (ranked):
score   4 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: solutions and avoided and quip ade wikiquotes 
No documents match.
KEY WORDs:> Query: circuits zealand 
No documents match.
KEY WORDs:> Query: multilevel allocator and elected whatiscs tertiarian or statesman 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: secure and europe and likely or having assumptions and yor 
No documents match.
KEY WORDs:> Query: metamorphosis and georgetown defers 
No documents match.
KEY WORDs:> Query: sprod 
No documents match.
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: disarmers or transitions slideway or hyman 
Matches 1 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: litwin and del pioneer texon defragmentation schoening 
No documents match.
KEY WORDs:> Query: aho and micrometers or hijra or peter motorola 
No documents match.
KEY WORDs:> Query: crunching corporate beck and unjam milpa and singly 
No documents match.
KEY WORDs:> Query: php presentations landis or aptos 
No documents match.
KEY WORDs:> Query: soccer and dating 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: abet decade belonged challenges 
No documents match.
KEY WORDs:> Query: lafayette attorney wisconsin or amember 
Matches 1 documents (ranked):
score   5 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: libm and permanent and models metaphyte 
No documents match.
KEY WORDs:> Query: portrait 
Matches 1 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: limitations ascc repeat attribute or ameliorated 
Matches 1 documents (ranked):
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: delaware ecotechnology nainsooks or rewakened trees wikidata 
No documents match.
KEY WORDs:> Query: disparity 
Matches 1 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: slavic or arbitrarily or kaufhold or minister 
Matches 4 documents (ranked):
score   4 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   2 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: rubrics reality and unauthorized gift and contains 
No documents match.
KEY WORDs:> Query: fiedler or basename and story 
Matches 1 documents (ranked):
score   2 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: kitamat or fultz polo or boolean or athletes akmuddar 
Matches 3 documents (ranked):
score   2 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: randy may and head and multinational or amaranths 
No documents match.
KEY WORDs:> Query: insufficiencies subcostae 
No documents match.
KEY WORDs:> Query: hierarchy enable reduce 
No documents match.
KEY WORDs:> Query: reduce and herbert and gottfried and previewontop search 
No documents match.
KEY WORDs:> Query: feedback or pledges or javascript horsedrawing buchanite 
Matches 2 documents (ranked):
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: five 
Matches 3 documents (ranked):
score   4 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: modularity workalike or bsearch and platform or backspace 
Matches 2 documents (ranked):
score   2 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: pages fieldhouse 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: sues gear 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: transfer or sport partition engineer or attribute 
Matches 3 documents (ranked):
score   2 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: produces participants or personal and arpanet and splenitive 
No documents match.
KEY WORDs:> Query: china alimenter pliroforiki or text 
Matches 6 documents (ranked):
score  14 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score  13 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score  11 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score  10 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   8 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   7 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: productivity and algorithms or represent 
Matches 3 documents (ranked):
score   2 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   2 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   2 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: stack or notation editsectiononrightclick or draws 
Matches 6 documents (ranked):
score   3 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   2 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   2 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: approximately newspaper and wgcanonicalspecialpagename sector 
No documents match.
KEY WORDs:> Query: adjective and porter fighter and ragi or disciplinarian freed 
No documents match.
KEY WORDs:> Query: wgdigittransformtable 
Matches 6 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: lock 
Matches 1 documents (ranked):
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: together or ptarmic and forebodings 
Matches 6 documents (ranked):
score   5 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score   3 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   3 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   3 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   2 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: hop or char giovanna corrupt 
Matches 2 documents (ranked):
score   5 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: leiomyomatous and inter assigned binaries informally 
No documents match.
KEY WORDs:> Query: searchsuggest 
Matches 6 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: stripped 
Matches 1 documents (ranked):
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: hart unique anything 
No documents match.
KEY WORDs:> Query: dictionary resembles and mapped cite 
No documents match.
KEY WORDs:> Query: typedef 
Matches 1 documents (ranked):
score   2 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: scientist 
Matches 1 documents (ranked):
score   3 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: beslaver biological and folkloric or arbitrarily or corners 
Matches 2 documents (ranked):
score   3 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: naval and preconfine and things 
No documents match.
KEY WORDs:> Query: location col and server service and interview or lebow 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: steganophthalmatous 
No documents match.
KEY WORDs:> Error: bad character '/' in query.
KEY WORDs:> Query: alert or jay or chrissy characters thank 
Matches 6 documents (ranked):
score   3 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   2 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: bilharziasis or decree and usebetatoolbar 
Matches 1 documents (ranked):
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: kalaitzidakis fauvist locate and extract 
No documents match.
KEY WORDs:> Query: electronic and nist producer or richeted or typical and language 
Matches 4 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: doug specifically 
No documents match.
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: backward 
Matches 2 documents (ranked):
score   4 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: mitigated and missionaries or pax or lettering or doc or wikimediafoundation 
Matches 6 documents (ranked):
score   4 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: indoor 
Matches 1 documents (ranked):
score   2 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: libraries and protection 
Matches 2 documents (ranked):
score   3 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: php yonkersite indeed and dionisio or organized 
Matches 1 documents (ranked):
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: revenge or comes or childs and let preserved 
Matches 3 documents (ranked):
score   3 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: bsczi or longman and wgdefaultdateformat and email 
Matches 2 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: hookups 
No documents match.
KEY WORDs:> Query: angiofibroma or ruthene bus 
No documents match.
KEY WORDs:> Query: spaceflight 
Matches 1 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: sudo and ran coq and wmf 
No documents match.
KEY WORDs:> Query: transitions 
Matches 1 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: the or peek or inferno 
Matches 7 documents (ranked):
score 719 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score 466 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score 405 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score 397 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score 326 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score 319 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   6 docID     1 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/
-----------------------------------------------
KEY WORDs:> Query: intercircled and jewelry or directive harbison 
Matches 1 documents (ranked):
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: barrelhead 
No documents match.
KEY WORDs:> Query: correlated pointers 
Matches 1 documents (ranked):
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: chambray and guard or ubiquitous haverford conservative 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: august or enroll pass 
Matches 6 documents (ranked):
score 152 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   4 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   3 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   3 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: upsteps providence and sequencing folded anthemion or tertiarian 
No documents match.
KEY WORDs:> Query: hemmendinger 
Matches 1 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: scripps and shrubs statistical 
No documents match.
KEY WORDs:> Query: paulson sanctuaries interaction outstaid 
No documents match.
KEY WORDs:> Query: humify and corresponding or stavis 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: trustee or designed and window pamphlet 
Matches 1 documents (ranked):
score   2 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: cryogenics invention threshold completion former 
No documents match.
KEY WORDs:> Query: buffer grudgefully or bnf interantennal and interpreted 
No documents match.
KEY WORDs:> Query: posix wgtitle moved and pyogenin and misses or fire 
Matches 2 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: expr infrastructure alternatives or ingenital blending 
No documents match.
KEY WORDs:> Query: brent and sorted arithmetical ambitious 
No documents match.
KEY WORDs:> Query: honors and recipient searched or price sequences 
Matches 1 documents (ranked):
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: aspects or wordnetweb or ict registered 
Matches 1 documents (ranked):
score   6 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: rlogin 
Matches 1 documents (ranked):
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: previous celiagra converge libc and moor and choice 
No documents match.
KEY WORDs:> Query: multitude seminal 
No documents match.
KEY WORDs:> Query: algorithm and destroy and tech colfin clubhands nonentries 
No documents match.
KEY WORDs:> Query: opposite 
Matches 1 documents (ranked):
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: versa or governance longer and unorganic 
Matches 1 documents (ranked):
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: term christian 
Matches 1 documents (ranked):
score   2 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: bletchley ethinyl or design or myers coded 
Matches 7 documents (ranked):
score  18 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score  13 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   6 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   4 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   2 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   2 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score   1 docID     1 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/
-----------------------------------------------
KEY WORDs:> Query: rocky 
Matches 1 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: klink 
Matches 1 documents (ranked):
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: first or murmurs or nation surpassed and mergence 
Matches 6 documents (ranked):
score  25 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score  19 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score  15 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score  11 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   5 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   5 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: unneural 
No documents match.
KEY WORDs:> Query: wantrust and probes 
No documents match.
KEY WORDs:> Query: character and pottery machinule 
No documents match.
KEY WORDs:> Query: explosion roped 
No documents match.
KEY WORDs:> Query: compared or straightforward gallicolous or liveweight 
Matches 4 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: resize workbench or abc prime and rhodizite athlete 
No documents match.
KEY WORDs:> Query: mill and tiver flop paindemaine 
No documents match.
KEY WORDs:> Query: caches and banahan honor and based 
No documents match.
KEY WORDs:> Query: limu or reallocation miseases brought or internationalization sons 
Matches 1 documents (ranked):
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: statesman appear or involvement or ambiguity or subjectship 
Matches 2 documents (ranked):
score   2 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: lamedh and changing or bump 
Matches 1 documents (ranked):
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: certified or filling attributes and sculked athelia or accreditation 
Matches 2 documents (ranked):
score   5 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   2 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: transcribed and sip and coach or sequencing sectors 
No documents match.
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: refer helps or carbolating 
Matches 1 documents (ranked):
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: proposal fluid implements 
No documents match.
KEY WORDs:> Query: calls mainly or gottfried or bragged and enlarging limburgs 
Matches 3 documents (ranked):
score   2 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: scutulated or desiring 
Matches 1 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: baseball or anonymous railwaydom proprietary 
Matches 1 documents (ranked):
score   2 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: sullennesses repetition centre accreditation 
No documents match.
KEY WORDs:> Query: viewpagetarget and windows and criollos and tasks disruptive 
No documents match.
KEY WORDs:> Query: voice zero or samson and majos 
No documents match.
KEY WORDs:> Query: synecdoche unburstable and technicological 
No documents match.
KEY WORDs:> Query: mondiale science or teach stores or epideictic 
Matches 1 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: collision earn phone plain or supplied 
Matches 2 documents (ranked):
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: beflour reoperating and marrows wellesley pottery 
No documents match.
KEY WORDs:> Query: educators aspects or margetts spaces 
No documents match.
KEY WORDs:> Query: fiji and censky commentator dual traversal avoided 
No documents match.
KEY WORDs:> Query: csshover and attributes threshold change 
No documents match.
KEY WORDs:> Query: plymouth carries and provide 
No documents match.
KEY WORDs:> Query: skyrocket or contemporary computing reallocated 
Matches 1 documents (ranked):
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: mesityl or regarded straight watchdefault 
No documents match.
KEY WORDs:> Query: exhibit revolves and seconds identifying extensive 
No documents match.
KEY WORDs:> Query: netcat irix and plectrontra books or vms 
Matches 1 documents (ranked):
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: manuel argues and come move 
No documents match.
KEY WORDs:> Query: clarkson volacious or article despume or played 
Matches 1 documents (ranked):
score   2 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: concha scope nonaphasiac or nikolas or cleping or wxdev 
Matches 2 documents (ranked):
score   3 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: anjuta 
Matches 1 documents (ranked):
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
-----------------------------------------------
KEY WORDs:> Query: anaphoral or sign melopoeic html materials 
No documents match.
KEY WORDs:> Query: added 
Matches 5 documents (ranked):
score   5 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score   4 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   3 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
-----------------------------------------------
KEY WORDs:> Query: stl reproducing hashing dynamically appalachian and tailoring 
No documents match.
KEY WORDs:> Query: resulting or lifecycle 
Matches 4 documents (ranked):
score   2 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   2 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: oyez portraits or copying array 
Matches 2 documents (ranked):
score   2 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: dummy or thought shelves simply 
Matches 1 documents (ranked):
score   3 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> Query: nominal and annual 
No documents match.
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> Query: derelictly or generate and tanner antonakos artseditor normal 
No documents match.
KEY WORDs:> Query: wearable or absence hosted 
Matches 1 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
-----------------------------------------------
KEY WORDs:> Query: vui or acoustical puzzle half or pool 
Matches 4 documents (ranked):
score   3 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
score   2 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   2 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
-----------------------------------------------
KEY WORDs:> Query: water 
Matches 1 documents (ranked):
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
-----------------------------------------------
KEY WORDs:> Query: rookie nikolas or pagelanguagecode 
Matches 6 documents (ranked):
score   1 docID     7 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Computer_science.html
score   1 docID     6 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/C_(programming_language).html
score   1 docID     5 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Unix.html
score   1 docID     4 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Dartmouth_College.html
score   1 docID     3 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Hash_table.html
score   1 docID     2 : http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/wiki/Linked_list.html
-----------------------------------------------
KEY WORDs:> </code>

### bad usage, pageDirectory, indexFilename
<code> usage: ./querier pageDirectory indexFilename
pageDirectory wrong is not valid
indexFilename wrong is not valid </code>

### invalid query requests
<code> KEY WORDs:> Error: 'and' cannot be first
KEY WORDs:> --------
KEY WORDs:> Error: 'or' cannot be first
KEY WORDs:> --------
KEY WORDs:> Error: 'and' cannot be last
KEY WORDs:> --------
KEY WORDs:> Error: 'or' canont be last
KEY WORDs:> --------
KEY WORDs:> Error: 'and' and 'and' cannot be adjacent
KEY WORDs:> --------
KEY WORDs:> Error: 'or' and 'and' cannot be adjacent
KEY WORDs:> --------
KEY WORDs:> Error: 'and' and 'or' cannot be adjacent
KEY WORDs:> --------
KEY WORDs:> Error: 'or' and 'or' cannot be adjacent
KEY WORDs:> -------- 
KEY WORDs:> Error: bad character '1' in query.
KEY WORDs:> --------
KEY WORDs:> Error: bad character '-' in query.
KEY WORDs:> --------
KEY WORDs:> Query: aajdsfjksafd 
No documents match.
KEY WORDs:> -------- </code>
[paolo@flume ~/cs50/labs/tse/querier]$ 

