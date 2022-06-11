#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[], char* envp[]) {
  printf("Command-line arguments:\n");
  for (int i = 0; i < argc; i++) {
    printf("\targv[%2d]: %s\n", i, argv[i]);
  }

  printf("Environment variables:\n");
  for (int i = 0; envp[i] != NULL; i++) {
    printf("\tenvp[%3d]: %s\n", i, envp[i]);
  }

  return 0;
}
