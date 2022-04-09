#include <stdio.h>
#include <string.h>

typedef unsigned char* byte_pointer;

void showBytes(byte_pointer start, size_t len);
void showInt(int x);
void showFloat(float x);
void showPointer(void* x);
