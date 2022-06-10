CC = gcc
CFLAGS = -Wall -Werror -Og -fno-common
SRC = $(wildcard *.c)
PROGS = $(patsubst %.c,%,$(SRC))

all: $(PROGS)

%:%.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(PROGS) *.o
