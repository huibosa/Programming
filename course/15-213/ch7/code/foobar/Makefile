CC = gcc
CFLAGS = -Wall -Werror -Og -fno-common

PROGS = foobar3 \
				foobar4
all: foobar3 foobar4 foobar5

foobar3: foo3.c bar3.c
	$(CC) $(CFLAGS) -o $@ $^

foobar4: foo4.c bar4.c
	$(CC) $(CFLAGS) -o $@ $^

foobar5: foo5.c bar5.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(PROGS) *.o
