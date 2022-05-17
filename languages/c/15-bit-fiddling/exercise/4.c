// Write a function that takes two int arguments: a value and a bit position.
// Have the function return 1 if that particular bit position is 1, and have it
// return 0 otherwise. Test the function in a program.

#include <stdio.h>

int test_bit(int, int);

int main(void) {
  int num = 10;
  int pos = 2;

  printf("%d\n", test_bit(num, pos));

  return 0;
}

int test_bit(int n, int pos) { return (n >> pos) & 1; }
