#include "rio.h"
#include <stddef.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

ssize_t rio_readn(int fd, void* usrbuf, ssize_t n) {
  size_t nleft = n;
  ssize_t nread;
  char* bufp = usrbuf;

  while (nleft > 0) {
    if ((nread = read(fd, bufp, n)) < 0) {
      if (errno == EINTR) { // Interupted by signal handler return
        nread = 0;          // call read() again
      } else {
        return -1; // errno set by read()
      }
    } else if (nread == 0) {
      return 0;
    }
    nleft -= nread;
    bufp += nread;
  }
  return n - nleft;
}

ssize_t rio_writen(int fd, void* usrbuf, ssize_t n) {
  size_t nleft = n;
  ssize_t nwritten;
  char* bufp = usrbuf;

  while (nleft > 0) {
    if ((nwritten = write(fd, bufp, n)) <= 0) {
      if (errno == EINTR) { // Interupted by signal handler return
        nwritten = 0;       // call write() again
      } else {
        return -1; // errno set by write()
      }
    }
    nleft -= nwritten;
    bufp += nwritten;
  }
  return n;
}

void rio_readinitb(rio_t* rp, int fd) {
  rp->rio_fd = fd;
  rp->rio_cnt = 0;
  rp->rio_bufptr = rp->rio_buf;
}

static ssize_t rio_read(rio_t* rp, char* usrbuf, size_t n) {
  int cnt;

  // Refill if buffer is empty
  while (rp->rio_cnt <= 0) {
    rp->rio_cnt = read(rp->rio_fd, rp->rio_buf, sizeof(rp->rio_buf));
    if (rp->rio_cnt < 0) {
      if (errno != EINTR) {
        return -1;
      }
    } else if (rp->rio_cnt == 0) { // EOF
      break;
    } else { // Reset buffer ptr
      rp->rio_bufptr = rp->rio_buf;
    }
  }

  // Copy min(n, rp->rio_cnt) bytes from buf to user buf
  cnt = n;
  if (rp->rio_cnt < n) {
    cnt = rp->rio_cnt;
  }
  memcpy(usrbuf, rp->rio_bufptr, cnt);
  rp->rio_bufptr += cnt;
  rp->rio_cnt -= cnt;
  return cnt;
}

ssize_t rio_readlineb(rio_t* rp, void* usrbuf, size_t maxlen) {
  int rc, n;
  char ch;
  char* buf = usrbuf;

  for (n = 0; n < maxlen - 1; n++) {
    rc = rio_read(rp, &ch, sizeof(char));
    if (rc == 1) {
      *buf++ = ch;
      if (ch == '\n') {
        n++;
        break;
      }
    } else if (rc == 0) {
      if (n == 0) {
        return 0; // EOF, no data read
      } else {
        break; // EOF, some data was read
      }
    } else {
      return -1;
    }
  }
  *buf = '\0';

  return n;
}

ssize_t rio_readnb(rio_t* rp, void* usrbuf, size_t n) {
  int nread;
  int nleft = n;
  char* bufp = usrbuf;

  while (nleft > 0) {
    nread = rio_read(rp, bufp, nleft);
    if (nread < 0) {
      return -1;
    } else if (nread == 0) {
      return 0;
    }
    nleft -= nread;
    bufp += nread;
  }

  return n - nleft;
}
