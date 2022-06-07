#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <csapp.h>

void sigint_handler(int sig) {
  printf("Caught SIGINT\n");
  exit(0);
}

int main(void) {
  if (signal(SIGINT, sigint_handler) == SIG_ERR) {
    unix_error("signal error");
  }

  pause();

  return 0;
}
