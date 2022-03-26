#include <stdio.h>
#include <stdlib.h>

int main(void) {
  unsigned int p = 0x7f800000;
  unsigned int n = 0xff800000;
  unsigned int pnan = 0x7f800001;
  unsigned int nnan = 0xff800001;

  float positiveInfinity = *(float *)&p;
  float negativeInfinity = *(float *)&n;
  float positiveNaN = *(float *)&pnan;
  float negativeNan = *(float *)&nnan;

  printf("%f\n", positiveInfinity);
  printf("%f\n", negativeInfinity);
  printf("%f\n", positiveNaN);
  printf("%f\n", negativeNan);

  return 0;
}
