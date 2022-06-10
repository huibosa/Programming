// myls
#include <csapp.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char* argv[], char* env[]) {
  char* cols;

  if ((cols = getenv("COLUMNS")) != NULL) {
    char * buf[argc + 3];

    buf[0] = "/usr/bin/ls";
    for (int i = 1; i < argc; i++) {
      buf[i] = argv[i];
    }
    buf[argc] = "-w";
    buf[argc + 1] = cols;
    buf[argc + 2] = NULL;

    Execve("/usr/bin/ls", buf, env);
  } else {
    Execve("/usr/bin/ls", argv, env);
  }

  return 0;
}
