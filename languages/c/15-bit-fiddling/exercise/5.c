// 5. Write a function that rotates the bits of an unsigned int by a specified
// number of bits to the left. For instance, rotate_l(x,4) would move the bits
// in x four places to the left, and the bits lost from the left end would
// reappear at the right end. That is, the bit moved out of the high-order
// position is placed in the low-order position. Test the function in a
// program.

#include <limits.h>
#include <stdio.h>
#define UNIT_BIT sizeof(unsigned) * CHAR_BIT

void rotate_l(unsigned *, unsigned r);
char *itobs(unsigned, char *);

int main(void) {
  unsigned int a = 65504;
  char bs[UNIT_BIT + 1];

  printf("%s\n", itobs(a, bs));
  rotate_l(&a, 1);
  printf("%s\n", itobs(a, bs));
  rotate_l(&a, 2);
  printf("%s\n", itobs(a, bs));
  rotate_l(&a, 3);
  printf("%s\n", itobs(a, bs));
  rotate_l(&a, 4);
  printf("%s\n", itobs(a, bs));
  rotate_l(&a, 5);
  printf("%s\n", itobs(a, bs));
  rotate_l(&a, 4);
  printf("%s\n", itobs(a, bs));
  rotate_l(&a, 3);
  printf("%s\n", itobs(a, bs));
  rotate_l(&a, 2);
  printf("%s\n", itobs(a, bs));
  rotate_l(&a, 1);
  printf("%s\n", itobs(a, bs));

  return 0;
}

void rotate_l(unsigned *n, unsigned r) {
  unsigned mask = 1 << (sizeof(*n) * CHAR_BIT - 1);

  while (r--) {
    if ((*n & mask) == mask)
      *n = (*n << 1) + 1;
    else
      *n <<= 1;
  }
}

char *itobs(unsigned n, char *bs) {
  unsigned mask = 1 << (UNIT_BIT - 1);

  for (int i = 0; i < UNIT_BIT; ++i) {
    bs[i] = '0' + ((n & mask) == mask);
    mask >>= 1;
  }

  bs[UNIT_BIT] = '\0';

  return bs;
}
