#include <asm-generic/errno-base.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

ssize_t rio_readn(int fd, void* usrbuf, size_t n) {
  size_t nleft = n;
  ssize_t nread;
  char* bufp = usrbuf;

  while (nleft > 0) {
    if ((nread = read(fd, usrbuf, nleft)) < 0) {
      if (errno == EINTR) {
        nread = 0;
      } else {
        return -1;
      }
    } else if (nread == 0) {
      break;
    }
    nleft -= nread;
    bufp += nread;
  }
  return (n - nleft);
}
