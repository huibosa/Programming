#include <csapp.h>
#include <unistd.h>

int main(void) {
  char c;
  while (Read(STDIN_FILENO, &c, sizeof(char)) != 0) {
    write(STDOUT_FILENO, &c, sizeof(char));
  }

  return 0;
}
