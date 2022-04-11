#include <stdio.h>
#include <stdlib.h>

char big_array[1L << 24];  // 16 MB
char huge_array[1L << 31]; //  2 GB

int global = 0;

int useless() { return 0; }

int main(void) {
  void *p1, *p2, *p3, *p4;
  int   local = 0;

  p1 = malloc(1L << 28); // 256 MB
  p2 = malloc(1L << 8);  // 256 B
  p3 = malloc(1L << 32); // 4 GB
  p4 = malloc(1L << 8);  // 256 B

  printf("local: %p\n", &local);
  printf("global: %p\n", &global);
  printf("p1: %p\n", p1);
  printf("p3: %p\n", p3);
  printf("p4: %p\n", p4);
  printf("p2: %p\n", p2);
  printf("big_array: %p\n", big_array);
  printf("huge_array: %p\n", huge_array);
  printf("main(): %p\n", main);
  printf("usless(): %p\n", useless);

  return 0;
}
