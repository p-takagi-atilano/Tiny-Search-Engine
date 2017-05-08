# Makefile for 'crawler' module
#
# Paolo Takagi-Atilano, April 2017

LL = ../libcs50
L = ../common

PROG = crawler
OBJS = crawler.o
LLIBS = $(LL)/libcs50.a
LIBS = $(L)/common.a

CFLAGS = -Wall -pedantic -std=c11 -ggdb -I$(LL) -I$L -lcurl
CC = gcc
MAKE = make

$(PROG): $(OBJS) $(LIBS) $(LLIBS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(LLIBS) -o $(PROG)

crawler.o: $(LL)/bag.h $(LL)/hashtable.h $(LL)/webpage.h $(L)/pagedir.h



.PHONY: clean all valgrind

clean:
	rm -f *~ *.o *.dSYM
	rm -f $(PROG)

all: $(PROG)

valgrind: valgrind $(PROG)
