#include <csapp.h>

int main(void) {
  pid_t pid;
  int x = 1;

  pid = Fork();
  if (pid == 0) {
    printf("child : x=%d\n", ++x);
    exit(0);
  }

  printf("parent: x=%d\n", --x);
  exit(0);

  return 0;
}
