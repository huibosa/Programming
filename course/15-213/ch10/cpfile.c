#include <csapp.h>
#include <unistd.h>

int main(void) {
  rio_t rio;
  char buf[MAXLINE];
  int n;

  Rio_readinitb(&rio, STDIN_FILENO);
  while ((n = Rio_readlineb(&rio, buf, MAXLINE)) != 0) {
    Rio_writen(STDOUT_FILENO, buf, n);
  }

  return 0;
}
