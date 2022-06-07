#include <csapp.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
  pid_t pid;

  if ((pid = Fork()) == 0) {
    pause();
    printf("control should never reach here!\n");
    exit(0);
  }

  Kill(pid, SIGKILL);

  return 0;
}
