#include <asm-generic/errno-base.h>
#include <csapp.h>
#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define N 2
#define LEN 100

int main(void) {
  pid_t pid;
  int status, i;

  for (i = 0; i < N; ++i) {
    if ((pid = Fork()) == 0) {
      char* ptr = NULL;
      *ptr = 'h';
    }
  }

  while ((pid = waitpid(-1, &status, 0)) > 0) {
    if (WIFEXITED(status)) {
      printf("child %d terminated normally with exit status=%d\n", pid,
             WEXITSTATUS(status));
    } else if (WIFSIGNALED(status)) {
      char buf[LEN];
      sprintf(buf, "child %d terminated by signal %d", pid, WTERMSIG(status));
      psignal(WTERMSIG(status), buf);
    } else {
      printf("child %d terminated abnormally\n", pid);
    }
  }

  if (errno != ECHILD) {
    unix_error("waitpid error");
  }

  return 0;
}
