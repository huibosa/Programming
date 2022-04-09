#include <stdio.h>

/* This is very low-quality code.
It is intended to illustrate bad programming practices.
See Practice Problem 3.46. */
char* get_line() {
  char  buf[4];
  char* result;
  gets(buf);
  result = malloc(strlen(buf));
  strcpy(result, buf);
  return result;
}
