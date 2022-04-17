#include <stdio.h>

void inplaceSwap(int * x, int * y) {
  *y = *x ^ *y;
  *x = *x ^ *y;
  *y = *x ^ *y;
}

int main(void) {
  int x = 100;
  int y = 200;

  inplaceSwap(&x, &y);
  printf("%d\n", x);
  printf("%d\n", y);

  return 0;
}
