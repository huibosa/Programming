#ifndef RIO_H
#define RIO_H

#include <stdlib.h>
#include <asm-generic/errno-base.h>
#include <errno.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#define RIO_BUFSIZE 8192
#define MAXLINE 8192

typedef struct {
  int rio_fd;
  int rio_cnt;
  char* rio_bufptr;
  char rio_buf[RIO_BUFSIZE];
} rio_t;

ssize_t rio_readn(int fd, void* usrbuf, ssize_t n);
ssize_t rio_writen(int fd, void* usrbuf, ssize_t n);
ssize_t rio_readlineb(rio_t* rp, void* usrbuf, size_t maxlen);
void rio_readinitb(rio_t* rp, int fd);
ssize_t rio_readnb(rio_t* rp, void * usrbuf, size_t n);


#endif
