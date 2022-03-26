#include <stdio.h>
#include <string.h>

typedef unsigned char * bytePointer;

void showBytes(bytePointer start, size_t len);
void showInt(int x);
void showFloat(float x);
void showPointer(void *x);
