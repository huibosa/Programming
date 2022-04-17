#include <stdio.h>

#define POS_INFINITY 1e400
#define NEG_INFINITY (-POS_INFINITY)
#define NEG_ZERO (-1 / POS_INFINITY)

int main(void) {
  printf("%f\n", POS_INFINITY);
  printf("%f\n", NEG_INFINITY);
  printf("%f\n", NEG_ZERO);

  return 0;
}
