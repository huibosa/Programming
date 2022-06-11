#include <csapp.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

void handler(int sig) {
  return;
}

unsigned int snooze(unsigned int secs) {
  unsigned int rc = sleep(secs);
  printf("Slept for %d of %d secs.\n", secs - rc, secs);
  return rc;
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    printf("Usage: %s <secs>\n", argv[0]);
    exit(1);
  }

  if (signal(SIGINT, handler) == SIG_ERR) {
    unix_error("signal error\n");
  }

  (void)snooze(atoi(argv[1]));

  return 0;
}
