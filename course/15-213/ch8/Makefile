CC = gcc
CFLAGS = -Wall -g -Og
SRCS = $(wildcard *.c)
PROGS = $(patsubst %.c,%,$(SRCS))

all: $(PROGS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $< -lcsapp

clean:
	rm -f $(PROGS)
