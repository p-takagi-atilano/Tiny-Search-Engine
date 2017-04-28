# Makefile for 'crawler' module
#
# Paolo Takagi-Atilano, April 2017

L = ../libcs50
LL = ../common

PROG = crawler
OBJS = crawler.o
LIBS = $L/libcs50.a
LLIBS = $(LL)/common.a

CFLAGS = -Wall -pedantic -std=c11 -ggdb -I$(LL) -I$L -lcurl
CC = gcc
MAKE = make

$(PROG): $(OBJS) $(LIBS) $(LLIBS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(LLIBS) -o $(PROG)

crawler.o: $L/bag.h $L/hashtable.h $L/webpage.h $(LL)/pagedir.h



.PHONY: clean

clean:
	rm -f *~ *.o *.dSYM
	rm -f $(PROG)
