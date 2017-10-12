# Author: Dominik Harmim <xharmi00@stud.fit.vutbr.cz>

PRJ = c204
PROGS = $(PRJ)-test
C202DIR = ../c202
CC = gcc
CFLAGS = -Wall -std=c99 -pedantic -lm -I $(C202DIR)

vpath %.h $(C202DIR)
vpath %.c $(C202DIR)


.PHONY: all
all: $(PROGS)


$(PRJ)-test: $(PRJ).o $(PRJ)-test.o c202.o


$(PRJ).o: $(PRJ).c $(PRJ).h c202.h
$(PRJ)-test.o: $(PRJ)-test.c $(PRJ).h
c202.o: c202.c c202.h


.PHONY: clean
clean:
	rm -f *.o *.out $(PROGS)

