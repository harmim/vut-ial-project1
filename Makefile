# Author: Dominik Harmim <xharmi00@stud.fit.vutbr.cz>

VPATH = $(PROJ)

CC = gcc
CFLAGS := -Wall -std=c99 -pedantic -lm

PROJ = c202
EXECUTABLE = $(PROJ)-test
SRCS := $(PROJ)/*.c
OBJS = $(shell $(CC) $(CFLAGS) -MM $(SRCS) | grep ':' | cut -d ':' -f1 | tr '\n' ' ')

ifeq ($(PROJ), c204)
    C202DIR = c202
    CFLAGS := $(CFLAGS) -I $(C202DIR)
    SRCS := $(SRCS) $(C202DIR)/c202.c
    vpath %.c $(C202DIR)
    vpath %.h $(C202DIR)
endif

TEST_OUTPUT = test.output


.PHONY: all
all: $(EXECUTABLE)


$(EXECUTABLE): $(OBJS)


.PHONY: test
test: $(EXECUTABLE)
	./$(EXECUTABLE) > $(TEST_OUTPUT)
	diff -u $(TEST_OUTPUT) $(PROJ)/$(PROJ)-test.output


.PHONY: clean
clean:
	rm -rf *.o *.out $(EXECUTABLE) $(TEST_OUTPUT) $(DEPDIR)


# #################### Auto-Dependency Generation #####################
DEPDIR := .d
$(shell mkdir -p $(DEPDIR) > /dev/null)
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.Td

COMPILE.c = $(CC) $(DEPFLAGS) $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c
POSTCOMPILE = @mv -f $(DEPDIR)/$*.Td $(DEPDIR)/$*.d && touch $@

%.o: %.c
%.o: %.c $(DEPDIR)/%.d
	$(COMPILE.c) $(OUTPUT_OPTION) $<
	$(POSTCOMPILE)

$(DEPDIR)/%.d: ;
.PRECIOUS: $(DEPDIR)/%.d

include $(wildcard $(patsubst %, $(DEPDIR)/%.d, $(basename $(SRCS))))
# #####################################################################
