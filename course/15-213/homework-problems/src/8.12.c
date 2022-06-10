#include <csapp.h>
#include <stdio.h>
#include <stdlib.h>

//NOTE: Check for ./8.12 | wc -l
void doit(void) {
  Fork();
  Fork();
  printf("hello\n");
  return;
}

int main(void) {
  doit();
  printf("hello\n");

  return 0;
}
