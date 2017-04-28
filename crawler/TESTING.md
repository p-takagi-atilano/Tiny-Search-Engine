
### Going to the right directory, and cleaning everything out
[paolo@flume ~]$ cd cs50/labs/tse/
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
make[1]: *** indexer: No such file or directory.  Stop.
Makefile:28: recipe for target 'clean' failed
make: *** [clean] Error 2

### Making a new version of everything
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
gcc -Wall -pedantic -std=c11 -ggdb    -c -o pagedir.o pagedir.c
ar cr common.a pagedir.o
make[1]: Leaving directory '/net/tahoe3/paolo/cs50/labs/tse/common'
make -C crawler
make[1]: Entering directory '/net/tahoe3/paolo/cs50/labs/tse/crawler'
gcc -Wall -pedantic -std=c11 -ggdb -I../common -I../libcs50 -lcurl   -c -o crawler.o crawler.c
gcc -Wall -pedantic -std=c11 -ggdb -I../common -I../libcs50 -lcurl crawler.o ../libcs50/libcs50.a ../common/common.a -o crawler
make[1]: Leaving directory '/net/tahoe3/paolo/cs50/labs/tse/crawler'
make -C indexer
make[1]: *** indexer: No such file or directory.  Stop.
Makefile:10: recipe for target 'all' failed
make: *** [all] Error 2

### Moving into the crawler directory
[paolo@flume ~/cs50/labs/tse]$ ls crawler/
answers/  crawler*   crawler.o		Makefile   TESTING.md
crawled/  crawler.c  IMPLEMENTATION.md	README.md  testing.sh*
[paolo@flume ~/cs50/labs/tse]$ cd crawler

### Cleaning up to prove that I'm not cheating
[paolo@flume ~/cs50/labs/tse/crawler]$ rm -f crawled/*
[paolo@flume ~/cs50/labs/tse/crawler]$ ls crawled

### Trying some bad usages:
[paolo@flume ~/cs50/labs/tse/crawler]$ crawler
usage: crawler seedURL pageDirectory maxDepth
[paolo@flume ~/cs50/labs/tse/crawler]$ 
[paolo@flume ~/cs50/labs/tse/crawler]$ crawler http://old-www.cs.dartmouth.edu/index.html ./data/ 2
could not find given pageDirectory
[paolo@flume ~/cs50/labs/tse/crawler]$ crawler http://old-www.cs.dartmouth.edu/index.html crawled asdf
usage: maxDepth must be an int
[paolo@flume ~/cs50/labs/tse/crawler]$ crawler http://old-www.cs.dartmouth.edu/index.html crawled -1
usage: maxDepth must be >= 0

### seedURL points to non-existent server:
[paolo@flume ~/cs50/labs/tse/crawler]$ crawler http://www.ihopethatthisdoesntwork.com crawled 1
    FAILED: http://www.ihopethatthisdoesntwork.com

### seedURL poitns to non-internal server:
[paolo@flume ~/cs50/labs/tse/crawler]$ crawler http://www.google.com crawled 1
0   Fetched: http://www.google.com
0     Saved: http://www.google.com
0  Scanning: http://www.google.com
0     Found: http://www.google.com/imghp?hl=en&tab=wi
0  IgnExtrn: http://www.google.com/imghp?hl=en&tab=wi
0     Found: http://maps.google.com/maps?hl=en&tab=wl
0  IgnExtrn: http://maps.google.com/maps?hl=en&tab=wl
0     Found: https://play.google.com/?hl=en&tab=w8
0  IgnExtrn: https://play.google.com/?hl=en&tab=w8
0     Found: http://www.youtube.com/?tab=w1
0  IgnExtrn: http://www.youtube.com/?tab=w1
0     Found: http://news.google.com/nwshp?hl=en&tab=wn
0  IgnExtrn: http://news.google.com/nwshp?hl=en&tab=wn
0     Found: https://mail.google.com/mail/?tab=wm
0  IgnExtrn: https://mail.google.com/mail/?tab=wm
0     Found: https://drive.google.com/?tab=wo
0  IgnExtrn: https://drive.google.com/?tab=wo
0     Found: https://www.google.com/intl/en/options/
0  IgnExtrn: https://www.google.com/intl/en/options/
0     Found: http://www.google.com/history/optout?hl=en
0  IgnExtrn: http://www.google.com/history/optout?hl=en
0     Found: http://www.google.com/preferences?hl=en
0  IgnExtrn: http://www.google.com/preferences?hl=en
0     Found: https://accounts.google.com/ServiceLogin?hl=en&passive=true&continue=http://www.google.com/
0  IgnExtrn: https://accounts.google.com/ServiceLogin?hl=en&passive=true&continue=http://www.google.com/
0     Found: http://www.google.com/search?site=&amp;ie=UTF-8&amp;q=Marie+Harel&amp;oi=ddle&amp;ct=marie-harels-256th-birthday-global-5737545781477376&amp;hl=en&amp;sa=X&amp;ved=0ahUKEwjkiaLx2MfTAhVC22MKHbWPBbMQPQgD
0  IgnExtrn: http://www.google.com/search?site=&amp;ie=UTF-8&amp;q=Marie+Harel&amp;oi=ddle&amp;ct=marie-harels-256th-birthday-global-5737545781477376&amp;hl=en&amp;sa=X&amp;ved=0ahUKEwjkiaLx2MfTAhVC22MKHbWPBbMQPQgD
0     Found: http://www.google.com/advanced_search?hl=en&amp;authuser=0
0  IgnExtrn: http://www.google.com/advanced_search?hl=en&amp;authuser=0
0     Found: http://www.google.com/language_tools?hl=en&amp;authuser=0
0  IgnExtrn: http://www.google.com/language_tools?hl=en&amp;authuser=0
0     Found: http://www.google.com/intl/en/ads/
0  IgnExtrn: http://www.google.com/intl/en/ads/
0     Found: http://www.google.com/services/
0  IgnExtrn: http://www.google.com/services/
0     Found: https://plus.google.com/116899029375914044550
0  IgnExtrn: https://plus.google.com/116899029375914044550
0     Found: http://www.google.com/intl/en/about.html
0  IgnExtrn: http://www.google.com/intl/en/about.html
0     Found: http://www.google.com/intl/en/policies/privacy/
0  IgnExtrn: http://www.google.com/intl/en/policies/privacy/
0     Found: http://www.google.com/intl/en/policies/terms/
0  IgnExtrn: http://www.google.com/intl/en/policies/terms/
[paolo@flume ~/cs50/labs/tse/crawler]$ ls crawler
crawler*
[paolo@flume ~/cs50/labs/tse/crawler]$ ls crawled
1
[paolo@flume ~/cs50/labs/tse/crawler]$ rm crawled/*
rm: remove regular file 'crawled/1'? y

### seedURL points to valid server but non-existent page:
[paolo@flume ~/cs50/labs/tse/crawler]$ crawler http://old-www.cs.dartmouth.edu/blahblahblah crawled 1
    FAILED: http://old-www.cs.dartmouth.edu/blahblahblah
[paolo@flume ~/cs50/labs/tse/crawler]$ ls crawled

### Crawling a bit on a link:
[paolo@flume ~/cs50/labs/tse/crawler]$ crawler http://old-www.cs.dartmouth.edu/index.html crawled 0
0   Fetched: http://old-www.cs.dartmouth.edu/index.html
0     Saved: http://old-www.cs.dartmouth.edu/index.html
[paolo@flume ~/cs50/labs/tse/crawler]$ crawler http://old-www.cs.dartmouth.edu/index.html crawled 1
0   Fetched: http://old-www.cs.dartmouth.edu/index.html
0     Saved: http://old-www.cs.dartmouth.edu/index.html
0  Scanning: http://old-www.cs.dartmouth.edu/index.html
0     Found: http://web.cs.dartmouth.edu/
0  IgnExtrn: http://web.cs.dartmouth.edu/
0     Found: http://hamlin.cs.dartmouth.edu/~cs50/
0  IgnExtrn: http://hamlin.cs.dartmouth.edu/~cs50/
[paolo@flume ~/cs50/labs/tse/crawler]$ ls crawled
1

### Showing what I got
[paolo@flume ~/cs50/labs/tse/crawler]$ cat crawled/1
http://old-www.cs.dartmouth.edu/index.html
0
<head><title>Welcome to old-www.cs.dartmouth.edu</title></head>
<body>

<h1>Welcome to old-www.cs.dartmouth.edu</h1>

old-www used to be the CS Department at Dartmouth College's web aserver, but it was replaced a while ago.
It is also called <em>hamlin.cs.dartmouth.edu </em> and it is used by cs50 students for testing.

<ul>
<li>the new computer science department web server is <a href="http://web.cs.dartmouth.edu/"> here </a>
<li>the cs50 page is <a href="http://hamlin.cs.dartmouth.edu/~cs50/"> here </a>  
</ul>
</body>

[paolo@flume ~/cs50/labs/tse/crawler]$ rm crawled/*
rm: remove regular file 'crawled/1'? y
[paolo@flume ~/cs50/labs/tse/crawler]$ crawler http://old-www.cs.dartmouth.edu/index.html crawled 5
0   Fetched: http://old-www.cs.dartmouth.edu/index.html
0     Saved: http://old-www.cs.dartmouth.edu/index.html
0  Scanning: http://old-www.cs.dartmouth.edu/index.html
0     Found: http://web.cs.dartmouth.edu/
0  IgnExtrn: http://web.cs.dartmouth.edu/
0     Found: http://hamlin.cs.dartmouth.edu/~cs50/
0  IgnExtrn: http://hamlin.cs.dartmouth.edu/~cs50/
[paolo@flume ~/cs50/labs/tse/crawler]$ ls crawled
1
[paolo@flume ~/cs50/labs/tse/crawler]$ rm crawled/1
rm: remove regular file 'crawled/1'? y

### crawling with a new seed, in a way that forms a loop
### (~dfk loops with ~dfk/people)
[paolo@flume ~/cs50/labs/tse/crawler]$ crawler http://old-www.cs.dartmouth.edu/~dfk/people.html crawled 2
0   Fetched: http://old-www.cs.dartmouth.edu/~dfk/people.html
0     Saved: http://old-www.cs.dartmouth.edu/~dfk/people.html
0  Scanning: http://old-www.cs.dartmouth.edu/~dfk/people.html
0     Found: http://old-www.cs.dartmouth.edu/~dfk/index.html
0     Added: http://old-www.cs.dartmouth.edu/~dfk/index.html
0     Found: http://old-www.cs.dartmouth.edu/~dfk/favorites.html
0     Added: http://old-www.cs.dartmouth.edu/~dfk/favorites.html
0     Found: http://www.cs.virginia.edu/~evans/advice/prospective.html
0  IgnExtrn: http://www.cs.virginia.edu/~evans/advice/prospective.html
0     Found: http://old-www.cs.dartmouth.edu/~reza
0     Added: http://old-www.cs.dartmouth.edu/~reza
0     Found: http://thaw.org
0  IgnExtrn: http://thaw.org
0     Found: http://old-www.cs.dartmouth.edu/~dfk/postdoc.html
0     Added: http://old-www.cs.dartmouth.edu/~dfk/postdoc.html
0     Found: http://auracle-project.org
0  IgnExtrn: http://auracle-project.org
0     Found: https://www.linkedin.com/in/georgegboateng
0  IgnExtrn: https://www.linkedin.com/in/georgegboateng
0     Found: http://amulet-project.org
0  IgnExtrn: http://amulet-project.org
0     Found: http://old-www.cs.dartmouth.edu/~tahardin/
0     Added: http://old-www.cs.dartmouth.edu/~tahardin/
0     Found: http://amulet-project.org
0  IgnExtrn: http://amulet-project.org
0     Found: http://old-www.cs.dartmouth.edu/~rliu/
0     Added: http://old-www.cs.dartmouth.edu/~rliu/
0     Found: http://thaw.org
0  IgnExtrn: http://thaw.org
0     Found: http://old-www.cs.dartmouth.edu/~varun/
0     Added: http://old-www.cs.dartmouth.edu/~varun/
0     Found: http://amulet-project.org
0  IgnExtrn: http://amulet-project.org
0     Found: http://old-www.cs.dartmouth.edu/~tjp/
0     Added: http://old-www.cs.dartmouth.edu/~tjp/
0     Found: http://thaw.org
0  IgnExtrn: http://thaw.org
0     Found: http://www.cs.dartmouth.edu/~traviswp/
0  IgnExtrn: http://www.cs.dartmouth.edu/~traviswp/
0     Found: http://thaw.org
0  IgnExtrn: http://thaw.org
0     Found: http://amulet-project.org
0  IgnExtrn: http://amulet-project.org
0     Found: http://amulet-project.org
0  IgnExtrn: http://amulet-project.org
0     Found: http://amulet-project.org
0  IgnExtrn: http://amulet-project.org
0     Found: http://amulet-project.org
0  IgnExtrn: http://amulet-project.org
0     Found: http://amulet-project.org
0  IgnExtrn: http://amulet-project.org
0     Found: http://auracle-project.org
0  IgnExtrn: http://auracle-project.org
0     Found: http://old-www.cs.dartmouth.edu/~rapjr
0     Added: http://old-www.cs.dartmouth.edu/~rapjr
0     Found: http://thaw.org
0  IgnExtrn: http://thaw.org
0     Found: http://amulet-project.org
0  IgnExtrn: http://amulet-project.org
0     Found: http://auracle-project.org
0  IgnExtrn: http://auracle-project.org
0     Found: http://thaw.org
0  IgnExtrn: http://thaw.org
0     Found: http://amulet-project.org
0  IgnExtrn: http://amulet-project.org
0     Found: http://crawdad.org
0  IgnExtrn: http://crawdad.org
0     Found: http://www.cs.dartmouth.edu/~liang/
0  IgnExtrn: http://www.cs.dartmouth.edu/~liang/
0     Found: http://old-www.cs.dartmouth.edu/~amolina
0     Added: http://old-www.cs.dartmouth.edu/~amolina
0     Found: http://www.cs.dartmouth.edu/~sorber/
0  IgnExtrn: http://www.cs.dartmouth.edu/~sorber/
0     Found: http://www.cs.dartmouth.edu/~mhshin/
0  IgnExtrn: http://www.cs.dartmouth.edu/~mhshin/
0     Found: http://old-www.cs.dartmouth.edu/~sbratus
0     Added: http://old-www.cs.dartmouth.edu/~sbratus
0     Found: http://old-www.cs.dartmouth.edu/
0     Added: http://old-www.cs.dartmouth.edu/
0     Found: http://www.cs.indiana.edu/~kapadia/
0  IgnExtrn: http://www.cs.indiana.edu/~kapadia/
0     Found: http://cs.gmu.edu/~mlocasto/
0  IgnExtrn: http://cs.gmu.edu/~mlocasto/
0     Found: https://www.cs.etsu.edu/users/bhusev
0  IgnExtrn: https://www.cs.etsu.edu/users/bhusev
0     Found: http://www.linkedin.com/pub/5/887/487
0  IgnExtrn: http://www.linkedin.com/pub/5/887/487
0     Found: http://www.cs.st-andrews.ac.uk/~tristan/
0  IgnExtrn: http://www.cs.st-andrews.ac.uk/~tristan/
0     Found: http://www.cs.st-andrews.ac.uk/
0  IgnExtrn: http://www.cs.st-andrews.ac.uk/
0     Found: http://www.minkyong.com/
0  IgnExtrn: http://www.minkyong.com/
0     Found: http://www.cc.gatech.edu/~arnab/
0  IgnExtrn: http://www.cc.gatech.edu/~arnab/
0     Found: http://www.dti.unimi.it/~cremonini/
0  IgnExtrn: http://www.dti.unimi.it/~cremonini/
0     Found: http://old-www.cs.dartmouth.edu/~dfk/photos/graduation2008b.jpg
0  IgnExtrn: http://old-www.cs.dartmouth.edu/~dfk/photos/graduation2008b.jpg
0     Found: http://www.cs.dartmouth.edu/~shrirang
0  IgnExtrn: http://www.cs.dartmouth.edu/~shrirang
0     Found: http://www.cs.dartmouth.edu/reports/abstracts/TR2016-793/
0  IgnExtrn: http://www.cs.dartmouth.edu/reports/abstracts/TR2016-793/
0     Found: http://www.cs.dartmouth.edu/~aarathi
0  IgnExtrn: http://www.cs.dartmouth.edu/~aarathi
0     Found: http://www.cs.dartmouth.edu/reports/abstracts/TR2016-794/
0  IgnExtrn: http://www.cs.dartmouth.edu/reports/abstracts/TR2016-794/
0     Found: http://dxoig.mn
0  IgnExtrn: http://dxoig.mn
0     Found: http://www.cs.dartmouth.edu/reports/abstracts/TR2013-741/
0  IgnExtrn: http://www.cs.dartmouth.edu/reports/abstracts/TR2013-741/
0     Found: http://www.intel.com/content/www/us/en/research/intel-research.html
0  IgnExtrn: http://www.intel.com/content/www/us/en/research/intel-research.html
0     Found: http://www.linkedin.com/in/kerentan
0  IgnExtrn: http://www.linkedin.com/in/kerentan
0     Found: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2011-703/
0     Added: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2011-703/
0     Found: http://www.facebook.com
0  IgnExtrn: http://www.facebook.com
0     Found: http://www.linkedin.com/pub/2/270/2b8
0  IgnExtrn: http://www.linkedin.com/pub/2/270/2b8
0     Found: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2008-620/
0     Added: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2008-620/
0     Found: http://www.icebrg.io/
0  IgnExtrn: http://www.icebrg.io/
0     Found: http://www.linkedin.com/pub/ming-li/2/a66/788
0  IgnExtrn: http://www.linkedin.com/pub/ming-li/2/a66/788
0     Found: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2008-621/
0     Added: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2008-621/
0     Found: http://old-www.cs.dartmouth.edu/~solar/
0     Added: http://old-www.cs.dartmouth.edu/~solar/
0     Found: http://www.oracle.com/
0  IgnExtrn: http://www.oracle.com/
0     Found: http://www.linkedin.com/in/snanda
0  IgnExtrn: http://www.linkedin.com/in/snanda
0     Found: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2008-619/
0     Added: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2008-619/
0     Found: http://baesystems.com
0  IgnExtrn: http://baesystems.com
0     Found: http://www.linkedin.com/in/libosong
0  IgnExtrn: http://www.linkedin.com/in/libosong
0     Found: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2008-611/
0     Added: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2008-611/
0     Found: http://www.google.com/
0  IgnExtrn: http://www.google.com/
0     Found: http://researchmap.jp/kminami/
0  IgnExtrn: http://researchmap.jp/kminami/
0     Found: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2006-571/
0     Added: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2006-571/
0     Found: http://www.cs.uml.edu/~glchen/
0  IgnExtrn: http://www.cs.uml.edu/~glchen/
0     Found: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2004-514/
0     Added: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2004-514/
0     Found: http://old-www.cs.dartmouth.edu/~solar/
0     Found: http://www.linkedin.com/pub/ron-oldfield/3/963/9a0
0  IgnExtrn: http://www.linkedin.com/pub/ron-oldfield/3/963/9a0
0     Found: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2003-459/
0     Added: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2003-459/
0     Found: http://old-www.cs.dartmouth.edu/~dfk/armada/
0     Added: http://old-www.cs.dartmouth.edu/~dfk/armada/
0     Found: http://www.cs.sandia.gov/~bright/9223.html
0  IgnExtrn: http://www.cs.sandia.gov/~bright/9223.html
0     Found: http://www.sandia.gov/
0  IgnExtrn: http://www.sandia.gov/
0     Found: http://www.linkedin.com/in/jonathanlb
0  IgnExtrn: http://www.linkedin.com/in/jonathanlb
0     Found: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2001-408/
0     Added: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2001-408/
0     Found: http://www.coloradocollege.edu
0  IgnExtrn: http://www.coloradocollege.edu
0     Found: http://www.jonh.net/~jonh/
0  IgnExtrn: http://www.jonh.net/~jonh/
0     Found: http://old-www.cs.dartmouth.edu/~dfk/jonh/research/dissertation/
0     Added: http://old-www.cs.dartmouth.edu/~dfk/jonh/research/dissertation/
0     Found: http://www.linkedin.com/in/nilsn
0  IgnExtrn: http://www.linkedin.com/in/nilsn
0     Found: http://old-www.cs.dartmouth.edu/reports/abstracts/TR96-300/
0     Added: http://old-www.cs.dartmouth.edu/reports/abstracts/TR96-300/
0     Found: http://old-www.cs.dartmouth.edu/~dfk/nils/galley.html
0     Added: http://old-www.cs.dartmouth.edu/~dfk/nils/galley.html
0     Found: http://old-www.cs.dartmouth.edu/~dfk/photos/PrasadMareGrad.jpg
0  IgnExtrn: http://old-www.cs.dartmouth.edu/~dfk/photos/PrasadMareGrad.jpg
0     Found: http://old-www.cs.dartmouth.edu/~dfk/photos/YunGrad.jpg
0  IgnExtrn: http://old-www.cs.dartmouth.edu/~dfk/photos/YunGrad.jpg
0     Found: http://old-www.cs.dartmouth.edu/~dfk/photos/MurthyGrad.jpg
0  IgnExtrn: http://old-www.cs.dartmouth.edu/~dfk/photos/MurthyGrad.jpg
0     Found: http://old-www.cs.dartmouth.edu/~dfk/photos/CorneliusGrad.jpg
0  IgnExtrn: http://old-www.cs.dartmouth.edu/~dfk/photos/CorneliusGrad.jpg
0     Found: http://old-www.cs.dartmouth.edu/~dfk/photos/TanGrad.jpg
0  IgnExtrn: http://old-www.cs.dartmouth.edu/~dfk/photos/TanGrad.jpg
0     Found: http://old-www.cs.dartmouth.edu/~dfk/photos/DeshpandeGrad.jpg
0  IgnExtrn: http://old-www.cs.dartmouth.edu/~dfk/photos/DeshpandeGrad.jpg
0     Found: http://old-www.cs.dartmouth.edu/~dfk/photos/MingLiGrad.jpg
0  IgnExtrn: http://old-www.cs.dartmouth.edu/~dfk/photos/MingLiGrad.jpg
0     Found: http://old-www.cs.dartmouth.edu/~dfk/photos/NandaGrad.jpg
0  IgnExtrn: http://old-www.cs.dartmouth.edu/~dfk/photos/NandaGrad.jpg
0     Found: http://old-www.cs.dartmouth.edu/~dfk/photos/SongGrad.jpg
0  IgnExtrn: http://old-www.cs.dartmouth.edu/~dfk/photos/SongGrad.jpg
0     Found: http://old-www.cs.dartmouth.edu/~dfk/photos/MinamiGrad.jpg
0  IgnExtrn: http://old-www.cs.dartmouth.edu/~dfk/photos/MinamiGrad.jpg
0     Found: http://old-www.cs.dartmouth.edu/~dfk/photos/ChenGrad.jpg
0  IgnExtrn: http://old-www.cs.dartmouth.edu/~dfk/photos/ChenGrad.jpg
0     Found: http://old-www.cs.dartmouth.edu/~dfk/photos/OldfieldGrad.jpg
0  IgnExtrn: http://old-www.cs.dartmouth.edu/~dfk/photos/OldfieldGrad.jpg
0     Found: http://old-www.cs.dartmouth.edu/~dfk/photos/BredinGrad.jpg
0  IgnExtrn: http://old-www.cs.dartmouth.edu/~dfk/photos/BredinGrad.jpg
0     Found: http://www.cs.dartmouth.edu/~tyun
0  IgnExtrn: http://www.cs.dartmouth.edu/~tyun
0     Found: http://old-www.cs.dartmouth.edu/~dfk/
0     Added: http://old-www.cs.dartmouth.edu/~dfk/
0     Found: http://www.cs.dartmouth.edu/reports/abstracts/TR2005-566/
0  IgnExtrn: http://www.cs.dartmouth.edu/reports/abstracts/TR2005-566/
0     Found: http://old-www.cs.dartmouth.edu/~dfk/
0     Found: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2004-513/
0     Added: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2004-513/
0     Found: https://www.linkedin.com/in/tingcai
0  IgnExtrn: https://www.linkedin.com/in/tingcai
0     Found: https://www.linkedin.com/in/saurabnog
0  IgnExtrn: https://www.linkedin.com/in/saurabnog
0     Found: http://www.crowcastle.net/preston/
0  IgnExtrn: http://www.crowcastle.net/preston/
0     Found: http://old-www.cs.dartmouth.edu/academics/honors.html
0     Added: http://old-www.cs.dartmouth.edu/academics/honors.html
0     Found: http://www.cs.dartmouth.edu/reports/abstracts/TR2000-372/
0  IgnExtrn: http://www.cs.dartmouth.edu/reports/abstracts/TR2000-372/
0     Found: http://www.cs.dartmouth.edu/reports/abstracts/TR2016-802/
0  IgnExtrn: http://www.cs.dartmouth.edu/reports/abstracts/TR2016-802/
0     Found: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2000-370/
0     Added: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2000-370/
0     Found: http://www.cs.dartmouth.edu/reports/abstracts/TR2008-623/
0  IgnExtrn: http://www.cs.dartmouth.edu/reports/abstracts/TR2008-623/
0     Found: http://old-www.cs.dartmouth.edu/reports/abstracts/TR94-218/
0     Added: http://old-www.cs.dartmouth.edu/reports/abstracts/TR94-218/
0     Found: http://www.kenharker.com/
0  IgnExtrn: http://www.kenharker.com/
0     Found: http://old-www.cs.dartmouth.edu/reports/abstracts/TR95-258/
0     Added: http://old-www.cs.dartmouth.edu/reports/abstracts/TR95-258/
0     Found: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2001-391/
0     Added: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2001-391/
0     Found: http://www.cs.dartmouth.edu/reports/abstracts/TR2013-734/
0  IgnExtrn: http://www.cs.dartmouth.edu/reports/abstracts/TR2013-734/
0     Found: http://www.cs.dartmouth.edu/reports/abstracts/TR2016-807/
0  IgnExtrn: http://www.cs.dartmouth.edu/reports/abstracts/TR2016-807/
0     Found: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2003-455/
0     Added: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2003-455/
0     Found: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2002-426/
0     Added: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2002-426/
0     Found: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2001-392/
0     Added: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2001-392/
0     Found: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2001-390/
0     Added: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2001-390/
0     Found: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2004-504/
0     Added: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2004-504/
0     Found: http://old-www.cs.dartmouth.edu/reports/abstracts/TR96-287/
0     Added: http://old-www.cs.dartmouth.edu/reports/abstracts/TR96-287/
0     Found: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2012-720/
0     Added: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2012-720/
0     Found: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2001-393/
0     Added: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2001-393/
0     Found: http://old-www.cs.dartmouth.edu/reports/abstracts/TR96-288/
0     Added: http://old-www.cs.dartmouth.edu/reports/abstracts/TR96-288/
0     Found: http://old-www.cs.dartmouth.edu/reports/abstracts/TR95-260/
0     Added: http://old-www.cs.dartmouth.edu/reports/abstracts/TR95-260/
0     Found: http://www.cs.dartmouth.edu/reports/abstracts/TR2016-790/
0  IgnExtrn: http://www.cs.dartmouth.edu/reports/abstracts/TR2016-790/
0     Found: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2002-427/
0     Added: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2002-427/
0     Found: http://old-www.cs.dartmouth.edu/~jbaek/
0     Added: http://old-www.cs.dartmouth.edu/~jbaek/
0     Found: http://metrosense.cs.dartmouth.edu/
0  IgnExtrn: http://metrosense.cs.dartmouth.edu/
0     Found: http://amulet-project.org
0  IgnExtrn: http://amulet-project.org
0     Found: http://thaw.org
0  IgnExtrn: http://thaw.org
0     Found: http://thaw.org
0  IgnExtrn: http://thaw.org
0     Found: http://www.ists.dartmouth.edu/projects/tish.html
0  IgnExtrn: http://www.ists.dartmouth.edu/projects/tish.html
0     Found: http://crawdad.org
0  IgnExtrn: http://crawdad.org
0     Found: http://crawdad.cs.dartmouth.edu
0  IgnExtrn: http://crawdad.cs.dartmouth.edu
0     Found: http://crawdad.cs.dartmouth.edu
0  IgnExtrn: http://crawdad.cs.dartmouth.edu
0     Found: http://old-www.cs.dartmouth.edu/~pumpkin
0     Added: http://old-www.cs.dartmouth.edu/~pumpkin
0     Found: http://www.linkedin.com/in/kobbyessien
0  IgnExtrn: http://www.linkedin.com/in/kobbyessien
0     Found: http://crawdad.cs.dartmouth.edu
0  IgnExtrn: http://crawdad.cs.dartmouth.edu
0     Found: http://old-www.cs.dartmouth.edu/~zhiyuan
0     Added: http://old-www.cs.dartmouth.edu/~zhiyuan
0     Found: http://www.cs.dartmouth.edu/~sensorlab/metrosense/
0  IgnExtrn: http://www.cs.dartmouth.edu/~sensorlab/metrosense/
0     Found: http://agent.cs.dartmouth.edu/
0  IgnExtrn: http://agent.cs.dartmouth.edu/
0     Found: http://old-www.cs.dartmouth.edu/~rus/
0     Added: http://old-www.cs.dartmouth.edu/~rus/
0     Found: http://www.cs.dartmouth.edu/~echen/
0  IgnExtrn: http://www.cs.dartmouth.edu/~echen/
0     Found: http://amulet-project.org
0  IgnExtrn: http://amulet-project.org
0     Found: http://agents.cs.dartmouth.edu
0  IgnExtrn: http://agents.cs.dartmouth.edu
0     Found: http://old-www.cs.dartmouth.edu/~dist
0     Added: http://old-www.cs.dartmouth.edu/~dist
0     Found: http://kerf.cs.dartmouth.edu
0  IgnExtrn: http://kerf.cs.dartmouth.edu
0     Found: http://old-www.cs.dartmouth.edu/~bennet
0     Added: http://old-www.cs.dartmouth.edu/~bennet
0     Found: http://old-www.cs.dartmouth.edu/~map
0     Added: http://old-www.cs.dartmouth.edu/~map
0     Found: http://old-www.cs.dartmouth.edu/~dist
0     Found: http://crawdad.org
0  IgnExtrn: http://crawdad.org
    FAILED: http://old-www.cs.dartmouth.edu/~map
    FAILED: http://old-www.cs.dartmouth.edu/~bennet
    FAILED: http://old-www.cs.dartmouth.edu/~dist
    FAILED: http://old-www.cs.dartmouth.edu/~rus/
    FAILED: http://old-www.cs.dartmouth.edu/~zhiyuan
    FAILED: http://old-www.cs.dartmouth.edu/~pumpkin
    FAILED: http://old-www.cs.dartmouth.edu/~jbaek/
    FAILED: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2002-427/
    FAILED: http://old-www.cs.dartmouth.edu/reports/abstracts/TR95-260/
    FAILED: http://old-www.cs.dartmouth.edu/reports/abstracts/TR96-288/
    FAILED: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2001-393/
    FAILED: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2012-720/
    FAILED: http://old-www.cs.dartmouth.edu/reports/abstracts/TR96-287/
    FAILED: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2004-504/
    FAILED: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2001-390/
    FAILED: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2001-392/
    FAILED: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2002-426/
    FAILED: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2003-455/
    FAILED: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2001-391/
    FAILED: http://old-www.cs.dartmouth.edu/reports/abstracts/TR95-258/
    FAILED: http://old-www.cs.dartmouth.edu/reports/abstracts/TR94-218/
    FAILED: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2000-370/
    FAILED: http://old-www.cs.dartmouth.edu/academics/honors.html
    FAILED: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2004-513/
1   Fetched: http://old-www.cs.dartmouth.edu/~dfk/
1     Saved: http://old-www.cs.dartmouth.edu/~dfk/
1  Scanning: http://old-www.cs.dartmouth.edu/~dfk/
1     Found: http://old-www.cs.dartmouth.edu/~dfk/ChampionInternationalProfessor.html
1     Added: http://old-www.cs.dartmouth.edu/~dfk/ChampionInternationalProfessor.html
1     Found: http://old-www.cs.dartmouth.edu/
1     Found: http://www.dartmouth.edu/
1  IgnExtrn: http://www.dartmouth.edu/
1     Found: http://old-www.cs.dartmouth.edu/~dfk/papers/wordle.html
1     Added: http://old-www.cs.dartmouth.edu/~dfk/papers/wordle.html
1     Found: http://www.wordle.net/
1  IgnExtrn: http://www.wordle.net/
1     Found: http://old-www.cs.dartmouth.edu/~dfk/vita.pdf
1  IgnExtrn: http://old-www.cs.dartmouth.edu/~dfk/vita.pdf
1     Found: http://old-www.cs.dartmouth.edu/~dfk/bio-dfk.txt
1  IgnExtrn: http://old-www.cs.dartmouth.edu/~dfk/bio-dfk.txt
1     Found: http://scholar.google.com/citations?user=w_Q7iBoAAAAJ
1  IgnExtrn: http://scholar.google.com/citations?user=w_Q7iBoAAAAJ
1     Found: http://orcid.org/0000-0001-7411-2783
1  IgnExtrn: http://orcid.org/0000-0001-7411-2783
1     Found: http://old-www.cs.dartmouth.edu/~dfk/papers/index.html
1     Added: http://old-www.cs.dartmouth.edu/~dfk/papers/index.html
1     Found: http://old-www.cs.dartmouth.edu/~dfk/people.html
1     Found: http://old-www.cs.dartmouth.edu/~dfk/teaching.html
1     Added: http://old-www.cs.dartmouth.edu/~dfk/teaching.html
1     Found: http://old-www.cs.dartmouth.edu/~dfk/postdoc.html
1     Found: http://web.cs.dartmouth.edu/news-events/research-programmer-position-available-david-kotzs-team
1  IgnExtrn: http://web.cs.dartmouth.edu/news-events/research-programmer-position-available-david-kotzs-team
1     Found: http://c4tbh.org
1  IgnExtrn: http://c4tbh.org
1     Found: http://www.ists.dartmouth.edu
1  IgnExtrn: http://www.ists.dartmouth.edu
1     Found: http://youtu.be/ngPflO_uyVo
1  IgnExtrn: http://youtu.be/ngPflO_uyVo
1     Found: http://thaw.org
1  IgnExtrn: http://thaw.org
1     Found: http://amulet-project.org
1  IgnExtrn: http://amulet-project.org
1     Found: https://www.youtube.com/watch?v=RmI3Pq1Z8Cs
1  IgnExtrn: https://www.youtube.com/watch?v=RmI3Pq1Z8Cs
1     Found: http://auracle-project.org
1  IgnExtrn: http://auracle-project.org
1     Found: http://www.healthit.gov/FACAS/health-it-policy-committee
1  IgnExtrn: http://www.healthit.gov/FACAS/health-it-policy-committee
1     Found: http://www.pbk.org/
1  IgnExtrn: http://www.pbk.org/
1     Found: http://www.ieee.org/web/membership/fellows/index.html
1  IgnExtrn: http://www.ieee.org/web/membership/fellows/index.html
1     Found: http://www.computer.org
1  IgnExtrn: http://www.computer.org
1     Found: http://www.acm.org
1  IgnExtrn: http://www.acm.org
1     Found: http://www.usenix.org/
1  IgnExtrn: http://www.usenix.org/
1     Found: http://www.cs.duke.edu/
1  IgnExtrn: http://www.cs.duke.edu/
1     Found: http://www.dartmouth.edu/
1  IgnExtrn: http://www.dartmouth.edu/
1     Found: http://www.alum.dartmouth.org/classes/86/
1  IgnExtrn: http://www.alum.dartmouth.org/classes/86/
1     Found: http://www.choate.edu/
1  IgnExtrn: http://www.choate.edu/
1     Found: http://photos.davidkotz.org/
1  IgnExtrn: http://photos.davidkotz.org/
1     Found: http://davidkotz.org/
1  IgnExtrn: http://davidkotz.org/
1     Found: http://www.cs.dartmouth.edu/~dfk/blog/
1  IgnExtrn: http://www.cs.dartmouth.edu/~dfk/blog/
1     Found: http://old-www.cs.dartmouth.edu/~dfk/kids.html
1     Added: http://old-www.cs.dartmouth.edu/~dfk/kids.html
1     Found: https://www.facebook.com/david.kotz.37
1  IgnExtrn: https://www.facebook.com/david.kotz.37
1     Found: http://www.crossroadsacademy.org
1  IgnExtrn: http://www.crossroadsacademy.org
1     Found: http://www.cies.org/US_scholars/
1  IgnExtrn: http://www.cies.org/US_scholars/
1     Found: http://www.cs.dartmouth.edu/~dfk/blog/Travel/India.html
1  IgnExtrn: http://www.cs.dartmouth.edu/~dfk/blog/Travel/India.html
1     Found: http://old-www.cs.dartmouth.edu/~dfk/seatpack/
1     Added: http://old-www.cs.dartmouth.edu/~dfk/seatpack/
1     Found: http://dfkotz.smugmug.com/House/Construction
1  IgnExtrn: http://dfkotz.smugmug.com/House/Construction
1     Found: http://dfkotz.smugmug.com/House/Projects/1998-Deck
1  IgnExtrn: http://dfkotz.smugmug.com/House/Projects/1998-Deck
1     Found: http://dfkotz.smugmug.com/House/2000-Addition
1  IgnExtrn: http://dfkotz.smugmug.com/House/2000-Addition
1     Found: http://dfkotz.smugmug.com/House/Projects/2005-Patio
1  IgnExtrn: http://dfkotz.smugmug.com/House/Projects/2005-Patio
1     Found: http://dfkotz.smugmug.com/House/Projects/2006-Walls
1  IgnExtrn: http://dfkotz.smugmug.com/House/Projects/2006-Walls
1     Found: http://dfkotz.smugmug.com/House/Projects/2006-Riverbank
1  IgnExtrn: http://dfkotz.smugmug.com/House/Projects/2006-Riverbank
1     Found: http://dfkotz.smugmug.com/House/Projects/2007-Boatshed
1  IgnExtrn: http://dfkotz.smugmug.com/House/Projects/2007-Boatshed
1     Found: http://where
1  IgnExtrn: http://where
1     Found: http://www.gnuplot.info
1  IgnExtrn: http://www.gnuplot.info
1     Found: http://old-www.cs.dartmouth.edu/~dfk/photos/Kotz-old/Kotz-PDP11e.jpg
1  IgnExtrn: http://old-www.cs.dartmouth.edu/~dfk/photos/Kotz-old/Kotz-PDP11e.jpg
1     Found: http://www.choate.edu/
1  IgnExtrn: http://www.choate.edu/
1     Found: http://old-www.cs.dartmouth.edu/~dfk/Kotz.vcf
1  IgnExtrn: http://old-www.cs.dartmouth.edu/~dfk/Kotz.vcf
1     Found: http://old-www.cs.dartmouth.edu/~dfk/visit-dartmouth.html
1     Added: http://old-www.cs.dartmouth.edu/~dfk/visit-dartmouth.html
2   Fetched: http://old-www.cs.dartmouth.edu/~dfk/visit-dartmouth.html
2     Saved: http://old-www.cs.dartmouth.edu/~dfk/visit-dartmouth.html
2   Fetched: http://old-www.cs.dartmouth.edu/~dfk/seatpack/
2     Saved: http://old-www.cs.dartmouth.edu/~dfk/seatpack/
2   Fetched: http://old-www.cs.dartmouth.edu/~dfk/kids.html
2     Saved: http://old-www.cs.dartmouth.edu/~dfk/kids.html
2   Fetched: http://old-www.cs.dartmouth.edu/~dfk/teaching.html
2     Saved: http://old-www.cs.dartmouth.edu/~dfk/teaching.html
2   Fetched: http://old-www.cs.dartmouth.edu/~dfk/papers/index.html
2     Saved: http://old-www.cs.dartmouth.edu/~dfk/papers/index.html
2   Fetched: http://old-www.cs.dartmouth.edu/~dfk/papers/wordle.html
2     Saved: http://old-www.cs.dartmouth.edu/~dfk/papers/wordle.html
2   Fetched: http://old-www.cs.dartmouth.edu/~dfk/ChampionInternationalProfessor.html
2     Saved: http://old-www.cs.dartmouth.edu/~dfk/ChampionInternationalProfessor.html
1   Fetched: http://old-www.cs.dartmouth.edu/~dfk/nils/galley.html
1     Saved: http://old-www.cs.dartmouth.edu/~dfk/nils/galley.html
1  Scanning: http://old-www.cs.dartmouth.edu/~dfk/nils/galley.html
1     Found: http://old-www.cs.dartmouth.edu/~dfk/nils/workload.html
1     Added: http://old-www.cs.dartmouth.edu/~dfk/nils/workload.html
1     Found: http://old-www.cs.dartmouth.edu/research/fleet
1     Added: http://old-www.cs.dartmouth.edu/research/fleet
1     Found: http://lovelace.nas.nasa.gov/Parallel/SP2/nas_sp2_home.html
1  IgnExtrn: http://lovelace.nas.nasa.gov/Parallel/SP2/nas_sp2_home.html
1     Found: http://old-www.cs.dartmouth.edu/~dfk/nils/patterns/patterns.html
1     Added: http://old-www.cs.dartmouth.edu/~dfk/nils/patterns/patterns.html
1     Found: http://old-www.cs.dartmouth.edu/~dfk/nils/galley/vesta-galley.tar.Z
1  IgnExtrn: http://old-www.cs.dartmouth.edu/~dfk/nils/galley/vesta-galley.tar.Z
1     Found: http://old-www.cs.dartmouth.edu/~dfk/nils/galley/struct.html
1     Added: http://old-www.cs.dartmouth.edu/~dfk/nils/galley/struct.html
1     Found: http://old-www.cs.dartmouth.edu/~dfk/nils/galley/inter.html
1     Added: http://old-www.cs.dartmouth.edu/~dfk/nils/galley/inter.html
1     Found: http://old-www.cs.dartmouth.edu/~dfk/nils/galley/man/man.html
1     Added: http://old-www.cs.dartmouth.edu/~dfk/nils/galley/man/man.html
1     Found: http://old-www.cs.dartmouth.edu/~dfk/nils/papers/galley.html
1     Added: http://old-www.cs.dartmouth.edu/~dfk/nils/papers/galley.html
1     Found: http://old-www.cs.dartmouth.edu/~dfk/nils/papers/ics.html
1     Added: http://old-www.cs.dartmouth.edu/~dfk/nils/papers/ics.html
1     Found: http://old-www.cs.dartmouth.edu/~dfk/nils/papers/gfsperf.html
1     Added: http://old-www.cs.dartmouth.edu/~dfk/nils/papers/gfsperf.html
1     Found: http://old-www.cs.dartmouth.edu/~dfk/nils/galley/galley.tar.Z
1  IgnExtrn: http://old-www.cs.dartmouth.edu/~dfk/nils/galley/galley.tar.Z
1     Found: http://old-www.cs.dartmouth.edu/~nils/index.html
1     Added: http://old-www.cs.dartmouth.edu/~nils/index.html
    FAILED: http://old-www.cs.dartmouth.edu/~nils/index.html
2   Fetched: http://old-www.cs.dartmouth.edu/~dfk/nils/papers/gfsperf.html
2     Saved: http://old-www.cs.dartmouth.edu/~dfk/nils/papers/gfsperf.html
2   Fetched: http://old-www.cs.dartmouth.edu/~dfk/nils/papers/ics.html
2     Saved: http://old-www.cs.dartmouth.edu/~dfk/nils/papers/ics.html
2   Fetched: http://old-www.cs.dartmouth.edu/~dfk/nils/papers/galley.html
2     Saved: http://old-www.cs.dartmouth.edu/~dfk/nils/papers/galley.html
2   Fetched: http://old-www.cs.dartmouth.edu/~dfk/nils/galley/man/man.html
2     Saved: http://old-www.cs.dartmouth.edu/~dfk/nils/galley/man/man.html
2   Fetched: http://old-www.cs.dartmouth.edu/~dfk/nils/galley/inter.html
2     Saved: http://old-www.cs.dartmouth.edu/~dfk/nils/galley/inter.html
2   Fetched: http://old-www.cs.dartmouth.edu/~dfk/nils/galley/struct.html
2     Saved: http://old-www.cs.dartmouth.edu/~dfk/nils/galley/struct.html
2   Fetched: http://old-www.cs.dartmouth.edu/~dfk/nils/patterns/patterns.html
2     Saved: http://old-www.cs.dartmouth.edu/~dfk/nils/patterns/patterns.html
    FAILED: http://old-www.cs.dartmouth.edu/research/fleet
2   Fetched: http://old-www.cs.dartmouth.edu/~dfk/nils/workload.html
2     Saved: http://old-www.cs.dartmouth.edu/~dfk/nils/workload.html
    FAILED: http://old-www.cs.dartmouth.edu/reports/abstracts/TR96-300/
    FAILED: http://old-www.cs.dartmouth.edu/~dfk/jonh/research/dissertation/
    FAILED: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2001-408/
1   Fetched: http://old-www.cs.dartmouth.edu/~dfk/armada/
1     Saved: http://old-www.cs.dartmouth.edu/~dfk/armada/
1  Scanning: http://old-www.cs.dartmouth.edu/~dfk/armada/
1     Found: http://www.cs.dartmouth.edu/~raoldfi
1  IgnExtrn: http://www.cs.dartmouth.edu/~raoldfi
1     Found: http://www.cs.dartmouth.edu/~dfk/
1  IgnExtrn: http://www.cs.dartmouth.edu/~dfk/
1     Found: http://old-www.cs.dartmouth.edu/~dfk/armada/papers/oldfield:armada.bib
1  IgnExtrn: http://old-www.cs.dartmouth.edu/~dfk/armada/papers/oldfield:armada.bib
1     Found: http://www.cs.dartmouth.edu/~dfk/papers/oldfield:armada.pdf
1  IgnExtrn: http://www.cs.dartmouth.edu/~dfk/papers/oldfield:armada.pdf
1     Found: http://old-www.cs.dartmouth.edu/~dfk/armada/papers/oldfield:armada-wip.bib
1  IgnExtrn: http://old-www.cs.dartmouth.edu/~dfk/armada/papers/oldfield:armada-wip.bib
1     Found: http://www.cs.dartmouth.edu/~dfk/armada/papers/oldfield:armada-wip.pdf
1  IgnExtrn: http://www.cs.dartmouth.edu/~dfk/armada/papers/oldfield:armada-wip.pdf
1     Found: http://old-www.cs.dartmouth.edu/~dfk/armada/papers/oldfield:emulab-tr.bib
1  IgnExtrn: http://old-www.cs.dartmouth.edu/~dfk/armada/papers/oldfield:emulab-tr.bib
1     Found: http://www.cs.dartmouth.edu/reports/abstracts/TR2002-433/
1  IgnExtrn: http://www.cs.dartmouth.edu/reports/abstracts/TR2002-433/
1     Found: http://old-www.cs.dartmouth.edu/~dfk/armada/papers/oldfield:framework.bib
1  IgnExtrn: http://old-www.cs.dartmouth.edu/~dfk/armada/papers/oldfield:framework.bib
1     Found: http://www.cs.dartmouth.edu/~dfk/papers/oldfield:framework.pdf
1  IgnExtrn: http://www.cs.dartmouth.edu/~dfk/papers/oldfield:framework.pdf
1     Found: http://old-www.cs.dartmouth.edu/~dfk/armada/papers/oldfield:restruct.bib
1  IgnExtrn: http://old-www.cs.dartmouth.edu/~dfk/armada/papers/oldfield:restruct.bib
1     Found: http://dx.doi.org/10.1007/s10586-006-4899-7
1  IgnExtrn: http://dx.doi.org/10.1007/s10586-006-4899-7
1     Found: http://old-www.cs.dartmouth.edu/~dfk/armada/papers/oldfield:thesis.bib
1  IgnExtrn: http://old-www.cs.dartmouth.edu/~dfk/armada/papers/oldfield:thesis.bib
1     Found: http://old-www.cs.dartmouth.edu/~dfk/armada/papers/oldfield:thesis-tr.bib
1  IgnExtrn: http://old-www.cs.dartmouth.edu/~dfk/armada/papers/oldfield:thesis-tr.bib
1     Found: http://www.cs.dartmouth.edu/reports/TR2003-459.pdf
1  IgnExtrn: http://www.cs.dartmouth.edu/reports/TR2003-459.pdf
1     Found: http://old-www.cs.dartmouth.edu/~dfk/armada/talks/oldfield:armada-talk-dartmouth2003.bib
1  IgnExtrn: http://old-www.cs.dartmouth.edu/~dfk/armada/talks/oldfield:armada-talk-dartmouth2003.bib
1     Found: http://old-www.cs.dartmouth.edu/~dfk/armada/talks/oldfield:armada-talk-dartmouth98.bib
1  IgnExtrn: http://old-www.cs.dartmouth.edu/~dfk/armada/talks/oldfield:armada-talk-dartmouth98.bib
1     Found: http://old-www.cs.dartmouth.edu/~dfk/armada/talks/oldfield:armada-talk-sandia1998.bib
1  IgnExtrn: http://old-www.cs.dartmouth.edu/~dfk/armada/talks/oldfield:armada-talk-sandia1998.bib
1     Found: http://old-www.cs.dartmouth.edu/~dfk/armada/talks/oldfield:armada-talk-sandia2000.bib
1  IgnExtrn: http://old-www.cs.dartmouth.edu/~dfk/armada/talks/oldfield:armada-talk-sandia2000.bib
1     Found: http://old-www.cs.dartmouth.edu/~dfk/armada/talks/oldfield:armada-talk-sandia2003.bib
1  IgnExtrn: http://old-www.cs.dartmouth.edu/~dfk/armada/talks/oldfield:armada-talk-sandia2003.bib
1     Found: http://www.cs.dartmouth.edu/~dfk/armada/papers/oldfield:sandia2003.pdf
1  IgnExtrn: http://www.cs.dartmouth.edu/~dfk/armada/papers/oldfield:sandia2003.pdf
1     Found: http://old-www.cs.dartmouth.edu/~dfk/armada/talks/oldfield:datagrids-talk-microsoft.bib
1  IgnExtrn: http://old-www.cs.dartmouth.edu/~dfk/armada/talks/oldfield:datagrids-talk-microsoft.bib
1     Found: http://old-www.cs.dartmouth.edu/~dfk/armada/talks/oldfield:seismic-talk-dartmouth96.bib
1  IgnExtrn: http://old-www.cs.dartmouth.edu/~dfk/armada/talks/oldfield:seismic-talk-dartmouth96.bib
1     Found: http://old-www.cs.dartmouth.edu/~dfk/armada/talks/oldfield:seismic-talk-sc95.bib
1  IgnExtrn: http://old-www.cs.dartmouth.edu/~dfk/armada/talks/oldfield:seismic-talk-sc95.bib
1     Found: http://old-www.cs.dartmouth.edu/~dfk/armada/talks/oldfield:thesis-defense.bib
1  IgnExtrn: http://old-www.cs.dartmouth.edu/~dfk/armada/talks/oldfield:thesis-defense.bib
1     Found: http://www.cs.dartmouth.edu/~dfk/armada/papers/oldfield:thesis-defense.pdf
1  IgnExtrn: http://www.cs.dartmouth.edu/~dfk/armada/papers/oldfield:thesis-defense.pdf
1     Found: http://old-www.cs.dartmouth.edu/~dfk/armada/talks/oldfield:thesis-proposal-talk.bib
1  IgnExtrn: http://old-www.cs.dartmouth.edu/~dfk/armada/talks/oldfield:thesis-proposal-talk.bib
1     Found: http://old-www.cs.dartmouth.edu/~dfk/armada/papers/oldfield:armada-emulab-tr.pdf
1  IgnExtrn: http://old-www.cs.dartmouth.edu/~dfk/armada/papers/oldfield:armada-emulab-tr.pdf
1     Found: http://old-www.cs.dartmouth.edu/~dfk/armada/papers/oldfield:armada-talk-sandia2003.pdf
1  IgnExtrn: http://old-www.cs.dartmouth.edu/~dfk/armada/papers/oldfield:armada-talk-sandia2003.pdf
1     Found: http://old-www.cs.dartmouth.edu/~dfk/armada/papers/oldfield:armada-wip.pdf
1  IgnExtrn: http://old-www.cs.dartmouth.edu/~dfk/armada/papers/oldfield:armada-wip.pdf
1     Found: http://old-www.cs.dartmouth.edu/~dfk/armada/papers/kotz:anl2002.pdf
1  IgnExtrn: http://old-www.cs.dartmouth.edu/~dfk/armada/papers/kotz:anl2002.pdf
1     Found: http://old-www.cs.dartmouth.edu/~dfk/armada/papers/oldfield:armada.pdf
1  IgnExtrn: http://old-www.cs.dartmouth.edu/~dfk/armada/papers/oldfield:armada.pdf
1     Found: http://old-www.cs.dartmouth.edu/~dfk/armada/papers/oldfield:emulab-tr.pdf
1  IgnExtrn: http://old-www.cs.dartmouth.edu/~dfk/armada/papers/oldfield:emulab-tr.pdf
1     Found: http://old-www.cs.dartmouth.edu/~dfk/armada/papers/ccgrid2001.ps.gz
1  IgnExtrn: http://old-www.cs.dartmouth.edu/~dfk/armada/papers/ccgrid2001.ps.gz
1     Found: http://old-www.cs.dartmouth.edu/~dfk/armada/papers/oldfield:framework.pdf
1  IgnExtrn: http://old-www.cs.dartmouth.edu/~dfk/armada/papers/oldfield:framework.pdf
1     Found: http://old-www.cs.dartmouth.edu/~dfk/armada/papers/design.ps.gz
1  IgnExtrn: http://old-www.cs.dartmouth.edu/~dfk/armada/papers/design.ps.gz
1     Found: http://old-www.cs.dartmouth.edu/~dfk/armada/papers/oldfield:sandia2003.pdf
1  IgnExtrn: http://old-www.cs.dartmouth.edu/~dfk/armada/papers/oldfield:sandia2003.pdf
1     Found: http://old-www.cs.dartmouth.edu/~dfk/armada/papers/datagrids.pdf
1  IgnExtrn: http://old-www.cs.dartmouth.edu/~dfk/armada/papers/datagrids.pdf
1     Found: http://old-www.cs.dartmouth.edu/~dfk/armada/papers/oldfield:armada-wip-talk.ppt
1  IgnExtrn: http://old-www.cs.dartmouth.edu/~dfk/armada/papers/oldfield:armada-wip-talk.ppt
1     Found: http://old-www.cs.dartmouth.edu/~dfk/armada/papers/oldfield:thesis-defense.pdf
1  IgnExtrn: http://old-www.cs.dartmouth.edu/~dfk/armada/papers/oldfield:thesis-defense.pdf
1     Found: http://hutchinson.belmont.ma.us/tth/
1  IgnExtrn: http://hutchinson.belmont.ma.us/tth/
    FAILED: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2003-459/
    FAILED: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2004-514/
    FAILED: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2006-571/
    FAILED: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2008-611/
    FAILED: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2008-619/
    FAILED: http://old-www.cs.dartmouth.edu/~solar/
    FAILED: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2008-621/
    FAILED: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2008-620/
    FAILED: http://old-www.cs.dartmouth.edu/reports/abstracts/TR2011-703/
1   Fetched: http://old-www.cs.dartmouth.edu/
1     Saved: http://old-www.cs.dartmouth.edu/
1  Scanning: http://old-www.cs.dartmouth.edu/
1     Found: http://web.cs.dartmouth.edu/
1  IgnExtrn: http://web.cs.dartmouth.edu/
1     Found: http://hamlin.cs.dartmouth.edu/~cs50/
1  IgnExtrn: http://hamlin.cs.dartmouth.edu/~cs50/
    FAILED: http://old-www.cs.dartmouth.edu/~sbratus
    FAILED: http://old-www.cs.dartmouth.edu/~amolina
1   Fetched: http://old-www.cs.dartmouth.edu/~rapjr
1     Saved: http://old-www.cs.dartmouth.edu/~rapjr
1  Scanning: http://old-www.cs.dartmouth.edu/~rapjr
1     Found: http://old-www.cs.dartmouth.edu/~rapjr/
1     Added: http://old-www.cs.dartmouth.edu/~rapjr/
2   Fetched: http://old-www.cs.dartmouth.edu/~rapjr/
2     Saved: http://old-www.cs.dartmouth.edu/~rapjr/
1   Fetched: http://old-www.cs.dartmouth.edu/~tjp/
1     Saved: http://old-www.cs.dartmouth.edu/~tjp/
1  Scanning: http://old-www.cs.dartmouth.edu/~tjp/
1     Found: http://web.cs.dartmouth.edu/
1  IgnExtrn: http://web.cs.dartmouth.edu/
1     Found: http://www.cs.dartmouth.edu/~dfk/
1  IgnExtrn: http://www.cs.dartmouth.edu/~dfk/
1     Found: https://thaw.org/
1  IgnExtrn: https://thaw.org/
1     Found: http://old-www.cs.dartmouth.edu/~tjp/TR2016-789.pdf
1  IgnExtrn: http://old-www.cs.dartmouth.edu/~tjp/TR2016-789.pdf
1     Found: http://infocom2016.ieee-infocom.org/program/main-technical-program
1  IgnExtrn: http://infocom2016.ieee-infocom.org/program/main-technical-program
1     Found: http://old-www.cs.dartmouth.edu/~tjp/./cs10/index.php
1     Added: http://old-www.cs.dartmouth.edu/~tjp/cs10/index.php
1     Found: http://web.cs.dartmouth.edu/contact-us
1  IgnExtrn: http://web.cs.dartmouth.edu/contact-us
1     Found: http://www.fybr-tech.com/
1  IgnExtrn: http://www.fybr-tech.com/
1     Found: http://www.uctc.net/research/papers/351.pdf
1  IgnExtrn: http://www.uctc.net/research/papers/351.pdf
2   Fetched: http://old-www.cs.dartmouth.edu/~tjp/cs10/index.php
2     Saved: http://old-www.cs.dartmouth.edu/~tjp/cs10/index.php
1   Fetched: http://old-www.cs.dartmouth.edu/~varun/
1     Saved: http://old-www.cs.dartmouth.edu/~varun/
1  Scanning: http://old-www.cs.dartmouth.edu/~varun/
    FAILED: http://old-www.cs.dartmouth.edu/~rliu/
1   Fetched: http://old-www.cs.dartmouth.edu/~tahardin/
1     Saved: http://old-www.cs.dartmouth.edu/~tahardin/
1  Scanning: http://old-www.cs.dartmouth.edu/~tahardin/
1   Fetched: http://old-www.cs.dartmouth.edu/~dfk/postdoc.html
1     Saved: http://old-www.cs.dartmouth.edu/~dfk/postdoc.html
1  Scanning: http://old-www.cs.dartmouth.edu/~dfk/postdoc.html
1     Found: http://www.cs.dartmouth.edu/~dfk/
1  IgnExtrn: http://www.cs.dartmouth.edu/~dfk/
1     Found: http://www.cs.dartmouth.edu
1  IgnExtrn: http://www.cs.dartmouth.edu
1     Found: http://www.dartmouth.edu
1  IgnExtrn: http://www.dartmouth.edu
1     Found: http://www.ists.dartmouth.edu
1  IgnExtrn: http://www.ists.dartmouth.edu
1     Found: http://old-www.cs.dartmouth.edu/~dfk/people.html
1     Found: http://www.cs.dartmouth.edu/~dfk/papers/index.html
1  IgnExtrn: http://www.cs.dartmouth.edu/~dfk/papers/index.html
1     Found: http://amulet-project.org
1  IgnExtrn: http://amulet-project.org
1     Found: http://thaw.org
1  IgnExtrn: http://thaw.org
1     Found: http://www.dartmouth.edu
1  IgnExtrn: http://www.dartmouth.edu
1     Found: http://www.movoto.com/blog/top-ten/best-college-towns/
1  IgnExtrn: http://www.movoto.com/blog/top-ten/best-college-towns/
1     Found: http://apply.interfolio.com/24689
1  IgnExtrn: http://apply.interfolio.com/24689
1     Found: http://www.cs.dartmouth.edu/~dfk/
1  IgnExtrn: http://www.cs.dartmouth.edu/~dfk/
1   Fetched: http://old-www.cs.dartmouth.edu/~reza
1     Saved: http://old-www.cs.dartmouth.edu/~reza
1  Scanning: http://old-www.cs.dartmouth.edu/~reza
1     Found: http://old-www.cs.dartmouth.edu/~reza/
1     Added: http://old-www.cs.dartmouth.edu/~reza/
2   Fetched: http://old-www.cs.dartmouth.edu/~reza/
2     Saved: http://old-www.cs.dartmouth.edu/~reza/
1   Fetched: http://old-www.cs.dartmouth.edu/~dfk/favorites.html
1     Saved: http://old-www.cs.dartmouth.edu/~dfk/favorites.html
1  Scanning: http://old-www.cs.dartmouth.edu/~dfk/favorites.html
1     Found: http://old-www.cs.dartmouth.edu/~dfk/index.html
1     Found: http://pages.cpsc.ucalgary.ca/~locasto/studying.html
1  IgnExtrn: http://pages.cpsc.ucalgary.ca/~locasto/studying.html
1     Found: http://greatresearch.org
1  IgnExtrn: http://greatresearch.org
1     Found: http://old-www.cs.dartmouth.edu/~dfk/favorites.bib
1  IgnExtrn: http://old-www.cs.dartmouth.edu/~dfk/favorites.bib
1     Found: http://www.icir.org/vern/papers/meas-strategies-imc04.pdf
1  IgnExtrn: http://www.icir.org/vern/papers/meas-strategies-imc04.pdf
1     Found: http://chronicle.com/article/How-to-Fail-in-Grant-Writing/125620/
1  IgnExtrn: http://chronicle.com/article/How-to-Fail-in-Grant-Writing/125620/
1     Found: http://doi.acm.org/10.1145/378267.378283
1  IgnExtrn: http://doi.acm.org/10.1145/378267.378283
1     Found: http://people.csail.mit.edu/mernst/advice/conferences-vs-journals.html
1  IgnExtrn: http://people.csail.mit.edu/mernst/advice/conferences-vs-journals.html
1     Found: http://www.cs.auckland.ac.nz/~pgut001/pubs/paper_howto.html
1  IgnExtrn: http://www.cs.auckland.ac.nz/~pgut001/pubs/paper_howto.html
1     Found: http://ieeexplore.ieee.org/iel1/2/2004/00055470.pdf
1  IgnExtrn: http://ieeexplore.ieee.org/iel1/2/2004/00055470.pdf
1     Found: http://ieeexplore.ieee.org/iel1/2/4492/00179116.pdf
1  IgnExtrn: http://ieeexplore.ieee.org/iel1/2/4492/00179116.pdf
1     Found: http://chronicle.com/article/Want-to-Change-Academic/134546/
1  IgnExtrn: http://chronicle.com/article/Want-to-Change-Academic/134546/
1     Found: https://vimeo.com/101543862
1  IgnExtrn: https://vimeo.com/101543862
1     Found: http://www.phdcomics.com/comics.php?f=1553
1  IgnExtrn: http://www.phdcomics.com/comics.php?f=1553
1     Found: http://lazowska.cs.washington.edu/jobs.pdf
1  IgnExtrn: http://lazowska.cs.washington.edu/jobs.pdf
1     Found: http://chronicle.com/article/The-CV-Doctor-Is-Back-/49086/
1  IgnExtrn: http://chronicle.com/article/The-CV-Doctor-Is-Back-/49086/
1     Found: http://chronicle.com/article/Show-Them-You-Really-Want-the/132281/
1  IgnExtrn: http://chronicle.com/article/Show-Them-You-Really-Want-the/132281/
1     Found: http://dx.doi.org/10.1145/197149.197154
1  IgnExtrn: http://dx.doi.org/10.1145/197149.197154
1     Found: http://dx.doi.org/10.1145/197892.197895
1  IgnExtrn: http://dx.doi.org/10.1145/197892.197895
1     Found: http://chronicle.com/article/Graduate-School-Is-a-Means-to/131316/
1  IgnExtrn: http://chronicle.com/article/Graduate-School-Is-a-Means-to/131316/
1     Found: http://www.cs.utah.edu/~lepreau/osdi94/keynote/abstract.html
1  IgnExtrn: http://www.cs.utah.edu/~lepreau/osdi94/keynote/abstract.html
1     Found: http://www.hpl.hp.com/research/ssp/papers/CMUemigrationCourse.2up.pdf
1  IgnExtrn: http://www.hpl.hp.com/research/ssp/papers/CMUemigrationCourse.2up.pdf
1     Found: http://sciencecareers.sciencemag.org/career_magazine/previous_issues/articles/2009_10_23/caredit.a0900128
1  IgnExtrn: http://sciencecareers.sciencemag.org/career_magazine/previous_issues/articles/2009_10_23/caredit.a0900128
1     Found: http://cacm.acm.org/magazines/2012/7/151226-googles-hybrid-approach-to-research/fulltext
1  IgnExtrn: http://cacm.acm.org/magazines/2012/7/151226-googles-hybrid-approach-to-research/fulltext
1     Found: http://dx.doi.org/10.1145/1467247.1467259
1  IgnExtrn: http://dx.doi.org/10.1145/1467247.1467259
1     Found: http://dx.doi.org/10.1145/1467247.1467260
1  IgnExtrn: http://dx.doi.org/10.1145/1467247.1467260
1     Found: http://www.stanford.edu/~ouster/cgi-bin/sayings.php
1  IgnExtrn: http://www.stanford.edu/~ouster/cgi-bin/sayings.php
1   Fetched: http://old-www.cs.dartmouth.edu/~dfk/index.html
1     Saved: http://old-www.cs.dartmouth.edu/~dfk/index.html
1  Scanning: http://old-www.cs.dartmouth.edu/~dfk/index.html
1     Found: http://old-www.cs.dartmouth.edu/~dfk/ChampionInternationalProfessor.html
1     Found: http://old-www.cs.dartmouth.edu/
1     Found: http://www.dartmouth.edu/
1  IgnExtrn: http://www.dartmouth.edu/
1     Found: http://old-www.cs.dartmouth.edu/~dfk/papers/wordle.html
1     Found: http://www.wordle.net/
1  IgnExtrn: http://www.wordle.net/
1     Found: http://old-www.cs.dartmouth.edu/~dfk/vita.pdf
1  IgnExtrn: http://old-www.cs.dartmouth.edu/~dfk/vita.pdf
1     Found: http://old-www.cs.dartmouth.edu/~dfk/bio-dfk.txt
1  IgnExtrn: http://old-www.cs.dartmouth.edu/~dfk/bio-dfk.txt
1     Found: http://scholar.google.com/citations?user=w_Q7iBoAAAAJ
1  IgnExtrn: http://scholar.google.com/citations?user=w_Q7iBoAAAAJ
1     Found: http://orcid.org/0000-0001-7411-2783
1  IgnExtrn: http://orcid.org/0000-0001-7411-2783
1     Found: http://old-www.cs.dartmouth.edu/~dfk/papers/index.html
1     Found: http://old-www.cs.dartmouth.edu/~dfk/people.html
1     Found: http://old-www.cs.dartmouth.edu/~dfk/teaching.html
1     Found: http://old-www.cs.dartmouth.edu/~dfk/postdoc.html
1     Found: http://web.cs.dartmouth.edu/news-events/research-programmer-position-available-david-kotzs-team
1  IgnExtrn: http://web.cs.dartmouth.edu/news-events/research-programmer-position-available-david-kotzs-team
1     Found: http://c4tbh.org
1  IgnExtrn: http://c4tbh.org
1     Found: http://www.ists.dartmouth.edu
1  IgnExtrn: http://www.ists.dartmouth.edu
1     Found: http://youtu.be/ngPflO_uyVo
1  IgnExtrn: http://youtu.be/ngPflO_uyVo
1     Found: http://thaw.org
1  IgnExtrn: http://thaw.org
1     Found: http://amulet-project.org
1  IgnExtrn: http://amulet-project.org
1     Found: https://www.youtube.com/watch?v=RmI3Pq1Z8Cs
1  IgnExtrn: https://www.youtube.com/watch?v=RmI3Pq1Z8Cs
1     Found: http://auracle-project.org
1  IgnExtrn: http://auracle-project.org
1     Found: http://www.healthit.gov/FACAS/health-it-policy-committee
1  IgnExtrn: http://www.healthit.gov/FACAS/health-it-policy-committee
1     Found: http://www.pbk.org/
1  IgnExtrn: http://www.pbk.org/
1     Found: http://www.ieee.org/web/membership/fellows/index.html
1  IgnExtrn: http://www.ieee.org/web/membership/fellows/index.html
1     Found: http://www.computer.org
1  IgnExtrn: http://www.computer.org
1     Found: http://www.acm.org
1  IgnExtrn: http://www.acm.org
1     Found: http://www.usenix.org/
1  IgnExtrn: http://www.usenix.org/
1     Found: http://www.cs.duke.edu/
1  IgnExtrn: http://www.cs.duke.edu/
1     Found: http://www.dartmouth.edu/
1  IgnExtrn: http://www.dartmouth.edu/
1     Found: http://www.alum.dartmouth.org/classes/86/
1  IgnExtrn: http://www.alum.dartmouth.org/classes/86/
1     Found: http://www.choate.edu/
1  IgnExtrn: http://www.choate.edu/
1     Found: http://photos.davidkotz.org/
1  IgnExtrn: http://photos.davidkotz.org/
1     Found: http://davidkotz.org/
1  IgnExtrn: http://davidkotz.org/
1     Found: http://www.cs.dartmouth.edu/~dfk/blog/
1  IgnExtrn: http://www.cs.dartmouth.edu/~dfk/blog/
1     Found: http://old-www.cs.dartmouth.edu/~dfk/kids.html
1     Found: https://www.facebook.com/david.kotz.37
1  IgnExtrn: https://www.facebook.com/david.kotz.37
1     Found: http://www.crossroadsacademy.org
1  IgnExtrn: http://www.crossroadsacademy.org
1     Found: http://www.cies.org/US_scholars/
1  IgnExtrn: http://www.cies.org/US_scholars/
1     Found: http://www.cs.dartmouth.edu/~dfk/blog/Travel/India.html
1  IgnExtrn: http://www.cs.dartmouth.edu/~dfk/blog/Travel/India.html
1     Found: http://old-www.cs.dartmouth.edu/~dfk/seatpack/
1     Found: http://dfkotz.smugmug.com/House/Construction
1  IgnExtrn: http://dfkotz.smugmug.com/House/Construction
1     Found: http://dfkotz.smugmug.com/House/Projects/1998-Deck
1  IgnExtrn: http://dfkotz.smugmug.com/House/Projects/1998-Deck
1     Found: http://dfkotz.smugmug.com/House/2000-Addition
1  IgnExtrn: http://dfkotz.smugmug.com/House/2000-Addition
1     Found: http://dfkotz.smugmug.com/House/Projects/2005-Patio
1  IgnExtrn: http://dfkotz.smugmug.com/House/Projects/2005-Patio
1     Found: http://dfkotz.smugmug.com/House/Projects/2006-Walls
1  IgnExtrn: http://dfkotz.smugmug.com/House/Projects/2006-Walls
1     Found: http://dfkotz.smugmug.com/House/Projects/2006-Riverbank
1  IgnExtrn: http://dfkotz.smugmug.com/House/Projects/2006-Riverbank
1     Found: http://dfkotz.smugmug.com/House/Projects/2007-Boatshed
1  IgnExtrn: http://dfkotz.smugmug.com/House/Projects/2007-Boatshed
1     Found: http://where
1  IgnExtrn: http://where
1     Found: http://www.gnuplot.info
1  IgnExtrn: http://www.gnuplot.info
1     Found: http://old-www.cs.dartmouth.edu/~dfk/photos/Kotz-old/Kotz-PDP11e.jpg
1  IgnExtrn: http://old-www.cs.dartmouth.edu/~dfk/photos/Kotz-old/Kotz-PDP11e.jpg
1     Found: http://www.choate.edu/
1  IgnExtrn: http://www.choate.edu/
1     Found: http://old-www.cs.dartmouth.edu/~dfk/Kotz.vcf
1  IgnExtrn: http://old-www.cs.dartmouth.edu/~dfk/Kotz.vcf
1     Found: http://old-www.cs.dartmouth.edu/~dfk/visit-dartmouth.html
[paolo@flume ~/cs50/labs/tse/crawler]$ ls crawled
1   11	13  15	17  19	20  22	24  26	28  3	31  5  7  9
10  12	14  16	18  2	21  23	25  27	29  30	4   6  8
[paolo@flume ~/cs50/labs/tse/crawler]$ rm -f crawled/*
[paolo@flume ~/cs50/labs/tse/crawler]$ ls crawled

### crawling our Wikipedia playground:
[paolo@flume ~/cs50/labs/tse/crawler]$ crawler http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/ crawled 1
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
[paolo@flume ~/cs50/labs/tse/crawler]$ ls crawled
1  2  3  4  5  6  7
[paolo@flume ~/cs50/labs/tse/crawler]$ cat 1
cat: 1: No such file or directory
[paolo@flume ~/cs50/labs/tse/crawler]$ cat crawled/1
http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/
0
<!-- Note: Template file not found, using internal one -->
<html xmlns="http://www.w3.org/1999/xhtml" lang="en">

<head>
	<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
	<meta name="description" content="HTTrack is an easy-to-use website mirror utility. It allows you to download a World Wide website from the Internet to a local directory,building recursively all structures, getting html, images, and other files from the server to your computer. Links are rebuiltrelatively so that you can freely browse to the local site (works with any browser). You can mirror several sites together so that you can jump from one toanother. You can, also, update an existing mirror site, or resume an interrupted download. The robot is fully configurable, with an integrated help" />
	<meta name="keywords" content="httrack, HTTRACK, HTTrack, winhttrack, WINHTTRACK, WinHTTrack, offline browser, web mirror utility, aspirateur web, surf offline, web capture, www mirror utility, browse offline, local  site builder, website mirroring, aspirateur www, internet grabber, capture de site web, internet tool, hors connexion, unix, dos, windows 95, windows 98, solaris, ibm580, AIX 4.0, HTS, HTGet, web aspirator, web aspirateur, libre, GPL, GNU, free software" />
	<title>Local index - HTTrack Website Copier</title>
  <!-- Mirror and index made by HTTrack Website Copier/3.47-27 [XR&CO'2013] -->
	<style type="text/css">
	<!--

body {
	margin: 0;  padding: 0;  margin-bottom: 15px;  margin-top: 8px;
	background: #77b;
}
body, td {
	font: 14px "Trebuchet MS", Verdana, Arial, Helvetica, sans-serif;
	}

#subTitle {
	background: #000;  color: #fff;  padding: 4px;  font-weight: bold; 
	}

#siteNavigation a, #siteNavigation .current {
	font-weight: bold;  color: #448;
	}
#siteNavigation a:link    { text-decoration: none; }
#siteNavigation a:visited { text-decoration: none; }

#siteNavigation .current { background-color: #ccd; }

#siteNavigation a:hover   { text-decoration: none;  background-color: #fff;  color: #000; }
#siteNavigation a:active  { text-decoration: none;  background-color: #ccc; }


a:link    { text-decoration: underline;  color: #00f; }
a:visited { text-decoration: underline;  color: #000; }
a:hover   { text-decoration: underline;  color: #c00; }
a:active  { text-decoration: underline; }

#pageContent {
	clear: both;
	border-bottom: 6px solid #000;
	padding: 10px;  padding-top: 20px;
	line-height: 1.65em;
 background-image: url(backblue.gif);
 background-repeat: no-repeat;
 background-position: top right;
	}

#pageContent, #siteNavigation {
	background-color: #ccd;
	}


.imgLeft  { float: left;   margin-right: 10px;  margin-bottom: 10px; }
.imgRight { float: right;  margin-left: 10px;   margin-bottom: 10px; }

hr { height: 1px;  color: #000;  background-color: #000;  margin-bottom: 15px; }

h1 { margin: 0;  font-weight: bold;  font-size: 2em; }
h2 { margin: 0;  font-weight: bold;  font-size: 1.6em; }
h3 { margin: 0;  font-weight: bold;  font-size: 1.3em; }
h4 { margin: 0;  font-weight: bold;  font-size: 1.18em; }

.blak { background-color: #000; }
.hide { display: none; }
.tableWidth { min-width: 400px; }

.tblRegular       { border-collapse: collapse; }
.tblRegular td    { padding: 6px;  background-image: url(fade.gif);  border: 2px solid #99c; }
.tblHeaderColor, .tblHeaderColor td { background: #99c; }
.tblNoBorder td   { border: 0; }


// -->
</style>

</head>

<table width="76%" border="0" align="center" cellspacing="0" cellpadding="3" class="tableWidth">
	<tr>
	<td id="subTitle">HTTrack Website Copier - Open Source offline browser</td>
	</tr>
</table>
<table width="76%" border="0" align="center" cellspacing="0" cellpadding="0" class="tableWidth">
<tr class="blak">
<td>
	<table width="100%" border="0" align="center" cellspacing="1" cellpadding="0">
	<tr>
	<td colspan="6"> 
		<table width="100%" border="0" align="center" cellspacing="0" cellpadding="10">
		<tr> 
		<td id="pageContent"> 
<!-- ==================== End prologue ==================== -->

<H1 ALIGN=Center>Index of locally available sites:</H1>
  <TABLE BORDER="0" WIDTH="100%" CELLSPACING="1" CELLPADDING="0">
<!-- Note: Template file not found, using internal one -->
		<TR>
			<TD BACKGROUND="fade.gif">
				&middot;
					<A HREF="wiki/Computer_science.html">
						Computer science - Wikipedia, the free encyclopedia
					</A>		
			</TD>
		</TR>
<!-- Note: Template file not found, using internal one -->
		<TR>
			<TD BACKGROUND="fade.gif">
				&middot;
					<A HREF="wiki/C_(programming_language).html">
						C (programming language) - Wikipedia, the free encyclopedia
					</A>		
			</TD>
		</TR>
<!-- Note: Template file not found, using internal one -->
		<TR>
			<TD BACKGROUND="fade.gif">
				&middot;
					<A HREF="wiki/Unix.html">
						Unix - Wikipedia, the free encyclopedia
					</A>		
			</TD>
		</TR>
<!-- Note: Template file not found, using internal one -->
		<TR>
			<TD BACKGROUND="fade.gif">
				&middot;
					<A HREF="wiki/Dartmouth_College.html">
						Dartmouth College - Wikipedia, the free encyclopedia
					</A>		
			</TD>
		</TR>
<!-- Note: Template file not found, using internal one -->
		<TR>
			<TD BACKGROUND="fade.gif">
				&middot;
					<A HREF="wiki/Hash_table.html">
						Hash table - Wikipedia, the free encyclopedia
					</A>		
			</TD>
		</TR>
<!-- Note: Template file not found, using internal one -->
		<TR>
			<TD BACKGROUND="fade.gif">
				&middot;
					<A HREF="wiki/Linked_list.html">
						Linked list - Wikipedia, the free encyclopedia
					</A>		
			</TD>
		</TR>
<!-- Note: Template file not found, using internal one -->
	</TABLE>
	<BR>
	<BR>
	<BR>
  	<H6 ALIGN="RIGHT">
	<I>Mirror and index made by HTTrack Website Copier [XR&amp;CO'2013]</I>
	</H6>
	<!-- Mirror and index made by HTTrack Website Copier/3.47-27 [XR&CO'2013] -->
	<!-- Thanks for using HTTrack Website Copier! -->

<!-- ==================== Start epilogue ==================== -->
		</td>
		</tr>
		</table>
	</td>
	</tr>
	</table>
</td>
</tr>
</table>

<table width="76%" border="0" align="center" valign="bottom" cellspacing="0" cellpadding="0">
	<tr>
	<td id="footer"><small>&copy; 2013 Xavier Roche & other contributors - Web Design: Kauler Leto.</small></td>
	</tr>
</table>

</body>

</html>


[paolo@flume ~/cs50/labs/tse/crawler]$ rm -f crawled/*
[paolo@flume ~/cs50/labs/tse/crawler]$ ls crawled

### crawling on our playground
[paolo@flume ~/cs50/labs/tse/crawler]$ crawler http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/ crawled 2
0   Fetched: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/
0     Saved: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/
0  Scanning: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/
0     Found: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/A.html
0     Added: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/A.html
1   Fetched: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/A.html
1     Saved: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/A.html
1  Scanning: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/A.html
1     Found: https://en.wikipedia.org/wiki/Algorithm
1  IgnExtrn: https://en.wikipedia.org/wiki/Algorithm
1     Found: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/B.html
1     Added: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/B.html
1     Found: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/index.html
1     Added: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/index.html
2   Fetched: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/index.html
2     Saved: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/index.html
2   Fetched: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/B.html
2     Saved: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/B.html
[paolo@flume ~/cs50/labs/tse/crawler]$ ls crawled
1  2  3  4
[paolo@flume ~/cs50/labs/tse/crawler]$ crawler http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/ crawled 4
0   Fetched: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/
0     Saved: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/
0  Scanning: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/
0     Found: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/A.html
0     Added: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/A.html
1   Fetched: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/A.html
1     Saved: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/A.html
1  Scanning: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/A.html
1     Found: https://en.wikipedia.org/wiki/Algorithm
1  IgnExtrn: https://en.wikipedia.org/wiki/Algorithm
1     Found: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/B.html
1     Added: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/B.html
1     Found: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/index.html
1     Added: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/index.html
2   Fetched: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/index.html
2     Saved: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/index.html
2  Scanning: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/index.html
2     Found: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/A.html
2   Fetched: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/B.html
2     Saved: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/B.html
2  Scanning: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/B.html
2     Found: https://en.wikipedia.org/wiki/Breadth-first_search
2  IgnExtrn: https://en.wikipedia.org/wiki/Breadth-first_search
2     Found: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/C.html
2     Added: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/C.html
2     Found: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/D.html
2     Added: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/D.html
2     Found: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/E.html
2     Added: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/E.html
2     Found: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/index.html
3   Fetched: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/E.html
3     Saved: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/E.html
3  Scanning: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/E.html
3     Found: https://en.wikipedia.org/wiki/ENIAC
3  IgnExtrn: https://en.wikipedia.org/wiki/ENIAC
3     Found: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/F.html
3     Added: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/F.html
3     Found: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/G.html
3     Added: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/G.html
3     Found: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/A.html
3     Found: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/index.html
4   Fetched: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/G.html
4     Saved: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/G.html
4   Fetched: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/F.html
4     Saved: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/F.html
3   Fetched: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/D.html
3     Saved: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/D.html
3  Scanning: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/D.html
3     Found: https://en.wikipedia.org/wiki/Depth-first_search
3  IgnExtrn: https://en.wikipedia.org/wiki/Depth-first_search
3     Found: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/index.html
3   Fetched: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/C.html
3     Saved: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/C.html
3  Scanning: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/C.html
3     Found: https://en.wikipedia.org/wiki/Computational_biology
3  IgnExtrn: https://en.wikipedia.org/wiki/Computational_biology
3     Found: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/D.html
3     Found: http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/index.html

### Showing what I got:
[paolo@flume ~/cs50/labs/tse/crawler]$ ls crawled
1  2  3  4  5  6  7  8	9
[paolo@flume ~/cs50/labs/tse/crawler]$ cat crawled/1
http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/
0
<html>
<title>home</title>
This is the home page for a CS50 TSE playground.
<a href=A.html>A</a>
</html>
[paolo@flume ~/cs50/labs/tse/crawler]$ cat crawled/2
http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/A.html
1
<html>
<title>A</title>
A is for <a href=https://en.wikipedia.org/wiki/Algorithm>Algorithm</a>.
<a href=B.html>B</a>
<a href=index.html>home</a>
</html>
[paolo@flume ~/cs50/labs/tse/crawler]$ cat crawled/3
http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/index.html
2
<html>
<title>home</title>
This is the home page for a CS50 TSE playground.
<a href=A.html>A</a>
</html>
[paolo@flume ~/cs50/labs/tse/crawler]$ cat crawled/4
http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/B.html
2
<html>
<title>B</title>
B is for <a href=https://en.wikipedia.org/wiki/Breadth-first_search>Breadth-first search</a>.
<a href=C.html>C</a>
<a href=D.html>D</a>
<a href=E.html>E</a>
<a href=index.html>home</a>
</html>
[paolo@flume ~/cs50/labs/tse/crawler]$ cat crawled/5
http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/E.html
3
<html>
<title>E</title>
E is for <a href=https://en.wikipedia.org/wiki/ENIAC>ENIAC</a>.
<a href=F.html>F</a>
<a href=G.html>G</a>
<a href=A.html>A</a>
<a href=index.html>home</a>
</html>
[paolo@flume ~/cs50/labs/tse/crawler]$ cat crawled/6
http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/G.html
4
<html>
<title>G</title>
G is for <a href=https://en.wikipedia.org/wiki/Graph_traversal>Graph traversal</a>.
<a href=H.html>H</a>
<a href=index.html>home</a>
</html>
[paolo@flume ~/cs50/labs/tse/crawler]$ cat crawled/7
http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/F.html
4
<html>
<title>F</title>
F is for <a href=https://en.wikipedia.org/wiki/Fast_Fourier_transform>Fast Fourier transform</a>.
<a href=H.html>H</a>
<a href=index.html>home</a>
</html>
[paolo@flume ~/cs50/labs/tse/crawler]$ cat crawled/8
http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/D.html
3
<html>
<title>D</title>
D is for <a href=https://en.wikipedia.org/wiki/Depth-first_search>Depth-first search</a>.
<a href=index.html>home</a>
</html>
[paolo@flume ~/cs50/labs/tse/crawler]$ cat crawled/9
http://old-www.cs.dartmouth.edu/~cs50/data/tse/letters/C.html
3
<html>
<title>C</title>
C is for <a href=https://en.wikipedia.org/wiki/Computational_biology>Computational biology</a>.
<a href=D.html>D</a>
<a href=index.html>home</a>
</html>
[paolo@flume ~/cs50/labs/tse/crawler]$ ls crawled
1  2  3  4  5  6  7  8	9
