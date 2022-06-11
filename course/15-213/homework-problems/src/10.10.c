#include <csapp.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
  rio_t rio;
  char buf[MAXLINE];
  int n;

  if (argc == 2) {
    int fd = Open(argv[1], O_RDONLY, 0);
    while ((n = rio_readn(fd, buf, MAXBUF)) != 0) {
      Rio_writen(STDOUT_FILENO, buf, n);
    }
    exit(0);
  }

  Rio_readinitb(&rio, STDIN_FILENO);
  while ((n = Rio_readlineb(&rio, buf, MAXLINE)) != 0) {
    Rio_writen(STDOUT_FILENO, buf, n);
  }

  return 0;
}
