#include <bits/types/sigset_t.h>
#include <csapp.h>
#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

volatile sig_atomic_t pid;

void sigchld_handler(int sig) {
  int olderrno = errno;
  pid = Waitpid(-1, NULL, 0);
  errno = olderrno;

  return;
}

void sigint_handler(int sig) { return; }

int main(void) {
  sigset_t mask, prev;

  Signal(SIGCHLD, sigchld_handler);
  Signal(SIGINT, sigint_handler);

  Sigemptyset(&mask);
  sigaddset(&mask, SIGCHLD);

  while (1) {
    Sigprocmask(SIG_BLOCK, &mask, &prev); // Block SIGCHLD
    if (Fork() == 0) {
      exit(0);
    }

    // Wait for SIGCHLD to be received
    pid = 0;
    while (!pid) {
      sigsuspend(&prev);
    }

    // Optionally unblock SIGCHLD
    Sigprocmask(SIG_SETMASK, &prev, NULL); 

    printf(".");
  }

  return 0;
}
