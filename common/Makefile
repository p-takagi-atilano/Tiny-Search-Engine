# Makefile for common library
# 	Builds and compliles all these utility functions into a library
#
# Paolo Takagi-Atilano, April 2017

L = ../libcs50

# object files, and teh target library
OBJS = pagedir.o index.o word.o
LIB = common.a

FLAGS = -I$L

CFLAGS = -Wall -pedantic -std=c11 -ggdb $(FLAGS)
CC = gcc
MAKE = make

# build the library by archiving object files
$(LIB): $(OBJS)
	ar cr $(LIB) $(OBJS)

# Dependencies: object files depend on header files
pagedir.o: pagedir.h $L/webpage.h $L/file.h
index.o: index.h $L/counters.h $L/hashtable.h $L/file.h
word.o: word.h

.PHONY: clean sourcelist

# list all the sources and docs in this directory.
sourcelist: Makefile *.md *.c *.h
	@ECHO $^

# clean up after out compilation
clean:
	rm -f $(LIB) *~ *.o
