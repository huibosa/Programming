CC = gcc
CFLAGS = -Wall

PROGS = intc intl intr

all: $(PROGS)

# Compile time interposition
intc: mymalloc.c int.c
	$(CC) $(CFLAGS) -DCOMPILETIME -c mymalloc.c
	$(CC) $(CFLAGS) -I. -o intc int.c mymalloc.o

runc:
	./intc 10 100 1000

# Link time interposition
intl: mymalloc.c int.c
	$(CC) $(CFLAGS) -DLINKTIME -c mymalloc.c
	$(CC) $(CFLAGS) -c int.c
	$(CC) $(CFLAGS) -Wl,--wrap,malloc -Wl,--wrap,free -o intl int.o mymalloc.o

runl:
	./intl 10 100 1000

# Run time interposition
intr: mymalloc.c int.c
	$(CC) $(CFLAGS) -DRUNTIME -shared -fpic -o mymalloc.so mymalloc.c -ldl
	$(CC) $(CFLAGS) -o intr int.c

runr:
	(LD_PRELOAD='./mymalloc.so' ./intr 10 100 1000)

clean:
	rm -f $(PROGS) *.o *.so
