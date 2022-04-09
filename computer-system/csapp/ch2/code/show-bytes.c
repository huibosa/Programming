#include "./show-bytes.h"
#include <stdio.h>
#include <string.h>

void showBytes(byte_pointer start, size_t len) {
  for (int i = 0; i < len; ++i) {
    printf("%.2x", start[i]);
  }
  printf("\n");
}

void showInt(int x) { showBytes((byte_pointer)&x, sizeof(int)); }

void showFloat(float x) { showBytes((byte_pointer)&x, sizeof(float)); }

void showPointer(void* x) { showBytes((byte_pointer)&x, sizeof(void*)); }

void test_show_bytes(int val) {
  int   ival = val;
  float fval = (float)val;
  int*  pval = &ival;
  showInt(ival);
  showFloat(fval);
  showPointer(pval);
  printf("%p\n", pval);
}
