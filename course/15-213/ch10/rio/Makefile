CC = gcc
CFLAGS = -Wall -g -Og
PROGS = cpfile

all: $(PROGS)

$(PROGS): $(PROGS).c rio.c
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean
clean:
	rm -f PROGS
