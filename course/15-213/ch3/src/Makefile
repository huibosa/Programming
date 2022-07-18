CC = gcc
CFLAGS = -Og -g
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
ASMS = $(SRCS:.c=.s)

.PHONY: clean

all: $(OBJS) $(ASMS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

%.s: %.c
	$(CC) $(CFLAGS) -S -o $@ $<

clean:
	rm -rf $(OBJS) $(ASMS)
