#include <asm-generic/errno-base.h>
#include <bits/types/sigset_t.h>
#include <csapp.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void handler(int sig) {
  pid_t pid;
  int olderrno = errno;

  Sio_puts("Handler called\n");

  while ((pid = waitpid(-1, NULL, WNOHANG | WUNTRACED)) > 0) {
    Sio_puts("Reaped child (");
    Sio_putl((long)(pid));
    Sio_puts(")\n");
  }

  if (errno != ECHILD) {
    Sio_error("waitpid error");
  }

  errno = olderrno;
  return;
}

int main(void) {
  pid_t pid;
  sigset_t maskOne, prevOne;

  Signal(SIGCHLD, handler);
  Sigemptyset(&maskOne);
  Sigaddset(&maskOne, SIGCHLD);

  Sigprocmask(SIG_BLOCK, &maskOne, &prevOne);
  for (int i = 0; i < 5; i++) {
    if ((pid = Fork()) == 0) {
      Sigprocmask(SIG_SETMASK, &prevOne, NULL);
      printf("Forked child %d\n", (int)getpid());
      exit(i + 1);
    }
  }

  Sleep(1);
  Sigprocmask(SIG_SETMASK, &prevOne, NULL);

  while (1) {
    ;
  }

  return 0;
}
