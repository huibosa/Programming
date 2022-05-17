// Write a function that takes an int argument and returns the number of “on”
// bits in the argument. Test the function in a program.

#include <stdio.h>

int nb_bits_on(int);

int main(void) {
  int n = 57;

  printf("There are %d bits on.\n", nb_bits_on(n));

  return 0;
}

int nb_bits_on(int n) {
  int nb = 0;

  while (n) {
    nb += n & 1;
    n >>= 1;
  }

  return nb;
}
