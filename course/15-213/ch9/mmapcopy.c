#include <csapp.h>

void mmapcopy(int fd, int size) {
  char* bufp;

  bufp = mmap(NULL, size, PROT_READ, MAP_PRIVATE, fd, 0);
  Write(1, bufp, size);
  return;
}

int main(int argc, char* argv[]) {
  struct stat stat;
  int fd;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  fd = Open(argv[1], O_RDONLY, 0);
  fstat(fd, &stat);

  mmapcopy(fd, stat.st_size);

  return 0;
}
