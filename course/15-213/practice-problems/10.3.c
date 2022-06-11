#include <csapp.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int fd;
  char c;

  fd = Open("foobar.txt", O_APPEND, 0);
  if (Fork() == 0) {
    Read(fd, &c, 1);
    exit(0);
  }
  Wait(NULL);
  Read(fd, &c, 1);
  printf("c = %c\n", c);

  return 0;
}
