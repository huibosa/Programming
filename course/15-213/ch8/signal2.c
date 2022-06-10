#include <asm-generic/errno-base.h>
#include <csapp.h>
#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void handler2(int sig) {
  pid_t pid;
  int olderrno = errno;

  while ((pid = (waitpid(-1, NULL, 0))) > 0) {
    // Sio_puts("Handler reaped child\n");
    Sio_puts("Handler reaped child ");
    Sio_putl((long) pid);
    Sio_puts("\n");
  }

  if (errno != ECHILD) {
    Sio_error("waitpid error");
  }
  Sleep(1);
  errno = olderrno;
}


int main(void) {
  char buf[MAXBUF];
  int n;

  if ((signal(SIGCHLD, handler2)) == SIG_ERR) {
    unix_error("signal error");
  }

  for (int i = 0; i < 3; i++) {
    if (Fork() == 0) {
      printf("Hello from child %d\n", (int)getpid());
      exit(0);
    }
  }

  if ((n = read(STDIN_FILENO, buf, sizeof(buf))) < 0) {
    unix_error("read");
  }

  printf("Parent processing input\n");
  while (1) {
    ;
  }

  return 0;
}
