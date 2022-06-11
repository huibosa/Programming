#include <csapp.h>
#include <stdio.h>

int main(void) {
  int fd1, fd2;

  fd1 = Open("foo.txt", O_RDONLY, 0);
  Close(fd1);
  fd2 = Open("baz.txt", O_RDONLY, 0);
  printf("fd3 = %d\n", fd2);

  return 0;
}
