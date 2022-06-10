#include <csapp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int mysystem(char* command) {
  pid_t pid;
  int status;

  if ((pid = Fork()) == 0) {
    char* argv[4] = { "", "-c", command, NULL, };
    execve("/bin/sh", argv, environ);
  }

  // Print child pid so we can kill it
  printf("Child pid : %d\n", pid);

  if (Waitpid(pid, &status, 0) > 0) {
    // Exit normally
    if (WIFEXITED(status)) {
      printf("status: %d\n", status);
      return WEXITSTATUS(status);
    }

    // Exit abnormally
    if (WIFSIGNALED(status)) {
      printf("status: %d\n", status);
      return WTERMSIG(status);
    }
  }
}

int main(int argc, char* argv[]) {
  int code = mysystem("yes");
  printf("code: %d\n", code);

  return 0;
}
