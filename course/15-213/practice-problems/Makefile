CC = gcc
CFLAGS = -Wall -g -Og
SRCS = $(wildcard *.c)
PROGS = $(patsubst %.c,%.out,$(SRCS))

all: $(PROGS)

%.out: %.c
	$(CC) $(CFLAGS) -o $@ $< -lcsapp

.PHONY: clean

clean:
	find ./ -type f -executeble -print0 | xargs -0 rm -rf --
