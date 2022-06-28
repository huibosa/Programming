CC = gcc
CFLAGS = -Wall -g -Og
LDLIBS = -lcsapp
SRCS = $(wildcard *.c)
PROGS = $(SRCS:.c=)

.PHONY: clean all

all: $(PROGS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $< $(LDLIBS)

clean:
	rm -f $(PROGS)
