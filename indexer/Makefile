# Makefile for 'indexer' module
#
# Paolo Takagi-Atilano, May 2017

L = ../libcs50
LL = ../common

PROG1 = indexer
PROG2 = indextest
OBJS1 = indexer.o
OBJS2 = indextest.o

LIBS = $(L)/libcs50.a
LLIBS = $(LL)/common.a

CFLAGS = -Wall -pedantic -std=c11 -ggdb -I$L -I$(LL)
CC = gcc
MAKE = make

all: $(PROG1) $(PROG2)

$(PROG1): $(OBJS1) $(LIBS) $(LLIBS)
	$(CC) $(CFLAGS) $(OBJS1) $(LLIBS) $(LIBS) -o $(PROG1)

$(PROG2): $(OBJS2) $(LIBS) $(LLIBS)
	$(CC) $(CFLAGS) $(OBJS2) $(LLIBS) $(LIBS) -o $(PROG2)

indexer.o: $(LL)/pagedir.h $(LL)/index.h $(LL)/word.h  $(L)/hashtable.h $(L)/counters.h $(L)/webpage.h $(L)/file.h

indextest.o: $(LL)/index.h $(L)/hashtable.h $(L)/counters.h

.PHONY: clean all

clean:
	rm -f *~ *.o *.dSYM
	rm -f $(PROG1)
	rm -f $(PROG2)
