#include <asm-generic/errno-base.h>
#include <csapp.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define N 10

int main(void) {
  pid_t pid;
  int status, i;

  for (i = 0; i < N; ++i) {
    if ((pid = Fork()) == 0) {
      exit(100 + i);
    }
  }

  while ((pid = waitpid(-1, &status, 0)) > 0) {
    if (WIFEXITED(status)) {
      printf("child %d terminated normally with exit status=%d\n", pid,
             WEXITSTATUS(status));
    } else {
      printf("child %d terminated abnormally\n", pid);
    }
  }
  pid = waitpid(-1, &status, 0);

  if (errno != ECHILD) {
    unix_error("waitpid error");
  }

  return 0;
}
