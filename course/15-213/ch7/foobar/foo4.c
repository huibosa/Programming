#include <stdio.h>

void f(void);

int x;

int main(void) {
  f();
  printf("x = %d\n", x);

  return 0;
}
