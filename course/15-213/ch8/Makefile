CC = gcc
CFLAGS = -Wall

PROGS = forks\
				myecho\
				shellex\
				sigint\
				kill

all: $(PROGS)

forks: forks.c
	$(CC) $(CFLAGS) -Og -o $@ $^ -lcsapp

myecho: myecho.c

shellex: shellex.c
	$(CC) $(CFLAGS) -Og -o $@ $^ -lcsapp

sigint: sigint.c
	$(CC) $(CFLAGS) -Og -o $@ $^ -lcsapp

kill: kill.c
	$(CC) $(CFLAGS) -Og -o $@ $^ -lcsapp

clean:
	rm -f $(PROGS) *.o
