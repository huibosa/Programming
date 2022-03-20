#include <stdio.h>

int uadd_ok(unsigned x, unsigned y) {
  return x + y >= x;
}

int tadd_ok(int x, int y) {
  int sum = x + y;
  int neg_over = x < 0 && y < 0 && sum >= 0;
  int pos_over = x >= 0 && y >= 0 && sum < 0;

  return !neg_over && !pos_over;
}
