#include <stdio.h>

float uu2double(unsigned short word0, unsigned short word1) {
  union {
    float f;
    unsigned short u[2];
  } temp;

  temp.u[0] = word0;
  temp.u[1] = word1;

  return temp.f;
}

int main(void) {
  unsigned short word0 = 0xe148;
  unsigned short word1 = 0x42f6;

  float res = uu2double(word0, word1);

  printf("%f\n", res);
}
