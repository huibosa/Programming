CC = gcc
CFLAGS = -Wall -Og

PROGS = prog2c \
				prog2l \
				prog2r

all: $(PROGS)

# Static library linked at compile time
prog2c: main2.o addvec.o multvec.o
	$(CC) $(CFLAGS) -c main2.c addvec.c multvec.c
	ar rcs libvector.a addvec.o multvec.o
	$(CC) $(CFLAGS) -static -o prog2c main2.o libvector.a
	# $(CC) $(CFLAGS) -static -o prog2c main2.o -L. -lvector

prog2l: main2.o libvector.so
	$(CC) $(CFLAGS) -o prog2l main2.c ./libvector.so

prog2r: dll.c
	$(CC) $(CFLAGS) -rdynamic -o prog2r dll.c -ldl

libvector.so addvec.c multvec.c:
	$(CC) $(CFLAGS) -shared -fpic -o libvector.so addvec.c multvec.c

clean:
	rm -f $(PROGS) *.o *.so *.a *.s
