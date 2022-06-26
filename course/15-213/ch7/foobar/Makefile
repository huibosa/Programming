CC = gcc
CFLAGS = -Wall -Og -fno-common
BARSRCS = $(wildcard bar*.c)
PROGS = $(patsubst %.c,foo%, $(BARSRCS))

# all: $(PROGS)

foobar6: bar6.c foo6.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(PROGS) *.o
