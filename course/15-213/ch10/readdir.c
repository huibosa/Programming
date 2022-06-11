#include <csapp.h>
#include <dirent.h>
#include <errno.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
  DIR* streamp;
  struct dirent* dep;

  streamp = Opendir(argv[1]);

  errno = 0;
  while ((dep = readdir(streamp)) != NULL) {
    printf("Found file: %s\n", dep->d_name);
  }
  if (errno != 0) {
    unix_error("readdir errno");
  }

  Closedir(streamp);

  return 0;
}
