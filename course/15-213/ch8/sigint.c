#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <csapp.h>

void sigint_handler(int sig) {
  printf("So you think you can stop the bomb with ctrl-c, do you?\n");
  sleep(2);
  printf("Well...");
  sleep(1);
  printf("OK. :)\n");
}

int main(void) {
  if (signal(SIGINT, sigint_handler)) {
    unix_error("signal error");
  }

  pause();

  return 0;
}
