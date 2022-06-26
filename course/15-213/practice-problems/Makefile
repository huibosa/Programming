CC = gcc
CFLAGS = -Wall -g -Og
SRCS = $(wildcard *.c)
PROGS = $(SRCS:.c=.out)

.PHONY: clean all install

all: $(PROGS)

%.out: %.c
	$(CC) $(CFLAGS) -o $@ $< -lcsapp

clean:
	find ./ -type f -executable -delete
