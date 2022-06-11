#include <csapp.h>
#include <unistd.h>

int main(void) {
  rio_t rio;
  int n;
  char buf[MAXBUF];

  rio_readinitb(&rio, STDIN_FILENO);
  while ((n = rio_readnb(&rio, buf, MAXBUF)) != 0) {
    Rio_writen(STDOUT_FILENO, buf, n);
  }

  return 0;
}
