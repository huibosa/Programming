#include <math.h>
#include <stdio.h>

int b2t(int x) {
  int tot = 0;
  int MASK = 0x1;

  for (int i = 0; i < 3; ++i, MASK <<= 1) {
    tot += (MASK & x);
  }

  return tot + -(MASK & x);
}

int main(void) {
  int x = 0xf;
  printf("%d\n", b2t(x));

  return 0;
}
