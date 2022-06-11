#include <csapp.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char* argv[]) {
  struct stat stat;
  char* type;
  char* readok;
  int fd;

  if (argc <= 1) {
    fd = 0;  // stdin
  } else {
    fd = atoi(argv[1]);
  }
  Fstat(fd, &stat);

  if (S_ISREG(stat.st_mode)) {
    type = "regular";
  } else if (S_ISDIR(stat.st_mode)) {
    type = "directory";
  } else {
    type = "other";
  }

  if (stat.st_mode & SI_USER) {
    readok = "yes";
  } else {
    readok = "no";
  }

  printf("type: %s, read: %s\n", type, readok);

  return 0;
}
