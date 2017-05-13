# Makefile for 'querier' module
#
# Paolo Takagi-Atilano, May 2017

L = ../libcs50
C = ../common

PROG = querier
OBJS = querier.o

TEST = fuzzquery
TOBJS = fuzzquery.o

LIBS = $(L)/libcs50.a
CLIBS = $(C)/common.a

CFLAGS = -Wall -pedantic -std=gnu11 -ggdb -I$L -I$C
CC = gcc
MAKE = make

all: $(PROG) $(TEST)

$(PROG): $(OBJS) $(LIBS) $(CLIBS)
	$(CC) $(CFLAGS) $(OBJS) $(CLIBS) $(LIBS) -o $(PROG)

$(TEST): $(TOBJS) $(LIBS)
	$(CC) $(CFLAGS) $(TOBJS) $(LIBS) -o $(TEST)

.PHONY: clean all

querier.o: $C/pagedir.h $C/index.h $C/word.h  $L/hashtable.h $L/counters.h $L/file.h

fuzzquery.o: $L/memory.h $L/file.h

clean:
	rm -f *~ *.o *.dSYM
	rm -f $(PROG)
	rm -f $(TEST)
