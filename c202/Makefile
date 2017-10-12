# Author: Dominik Harmim <xharmi00@stud.fit.vutbr.cz>

PRJ = c202
PROGS = $(PRJ)-test
CC = gcc
CFLAGS = -Wall -std=c99 -pedantic -lm


.PHONY: all
all: $(PROGS)


$(PRJ)-test: $(PRJ).o $(PRJ)-test.o


$(PRJ).o: $(PRJ).c $(PRJ).h
$(PRJ)-test.o: $(PRJ)-test.c $(PRJ).h


.PHONY: clean
clean:
	rm -f *.o *.out $(PROGS)
