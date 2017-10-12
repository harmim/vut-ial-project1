# Author: Dominik Harmim <xharmi00@stud.fit.vutbr.cz>

PRJ = c206
PROGS = $(PRJ)-test
CC = gcc
CFLAGS = -Wall -std=c99 -pedantic -lm
TEST_OUTPUT = test.output


.PHONY: all
all: $(PROGS)


$(PRJ)-test: $(PRJ).o $(PRJ)-test.o


$(PRJ).o: $(PRJ).c $(PRJ).h
$(PRJ)-test.o: $(PRJ)-test.c $(PRJ).h


.PHONY: test
test: $(PRJ)-test
	./$(PRJ)-test > $(TEST_OUTPUT)
	diff -u $(TEST_OUTPUT) $(PRJ)-test.output


.PHONY: clean
clean:
	rm -f *.o *.out $(PROGS) $(TEST_OUTPUT)
