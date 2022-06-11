#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "rio.h"

int main(void) {
  int n;
  rio_t rio;
  char buf[MAXLINE];

  // int fd = open("./text", O_CREAT, "r");
  // rio_readinitb(&rio, fd);
  rio_readinitb(&rio, STDIN_FILENO);

  while ((n = rio_readlineb(&rio, buf, MAXLINE)) != 0) {
    rio_writen(STDOUT_FILENO, buf, n);
  }

  return 0;
}
