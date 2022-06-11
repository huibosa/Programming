CC = gcc
CFLAGS = -Wall -Og -g
SRCS = $(wildcard *.c)
PROGS = $(patsubst %.c,%,$(SRCS))

all: $(PROGS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $< -lcsapp

.PHONY: clean
clean:
	find ./ -type f -executable -print0 | xargs -0 rm -f --
