#include "./showbytes.h"
#include <stdio.h>
#include <string.h>

void showBytes(bytePointer start, size_t len) {
  for (int i = 0; i < len; ++i) {
    printf("%.2x", start[i]);
  }
  printf("\n");
}

void showInt(int x) { showBytes((bytePointer)&x, sizeof(int)); }

void showFloat(float x) { showBytes((bytePointer)&x, sizeof(float)); }

void showPointer(void *x) { showBytes((bytePointer)&x, sizeof(void *)); }

void testShowBytes(int val) {
  int ival = val;
  float fval = (float)val;
  int *pval = &ival;
  showInt(ival);
  showFloat(fval);
  showPointer(pval);
  printf("%p\n", pval);
}
