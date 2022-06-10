#include <bits/types/sigset_t.h>
#include <csapp.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

volatile long counter = 2;

void handler1(int sig) {
  sigset_t mask, preMask;

  Sigfillset(&mask);
  Sigprocmask(SIG_BLOCK, &mask, &preMask);
  Sio_putl(--counter);
  Sigprocmask(SIG_SETMASK, &preMask, NULL);

  _exit(0);
}

int main(void) {
  pid_t pid;
  sigset_t mask, preMask;

  printf("%ld", counter);
  fflush(stdout);

  signal(SIGUSR1, handler1);
  if ((pid = Fork()) == 0) {
    while (1) {
      ;
    }
  }
  Kill(pid, SIGUSR1);
  Waitpid(-1, NULL, 0);

  Sigfillset(&mask);
  Sigprocmask(SIG_BLOCK, &mask, &preMask);
  printf("%ld", ++counter);
  Sigprocmask(SIG_SETMASK, &preMask, NULL);

  return 0;
}
