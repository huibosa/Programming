#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <wait.h>

#define N 2

// * fork0 - The simplest fork example
// * Call once, return twice
// * Creates child that is identical to parent
// * Returns 0 to child process
// * Returns child PID to parent process
void fork0() {
  if (fork() == 0) {
    printf("Hello from child\n");
  } else {
    printf("Hello from parent\n");
  }
}

// * fork1 - Simple fork example
// * Parent and child both run same code
// * Child starts with identical private state
void fork1() {
  int x = 1;
  pid_t pid = fork();

  if (pid == 0) {
    printf("Child has x = %d\n", ++x);
  } else {
    printf("Parent has x = %d\n", --x);
  }
  printf("Bye from process %d with x = %d\n", getpid(), x);
}

void fork7() {
  if (fork() == 0) {
    // Child
    printf("Terminating Child, PID = %d\n", getpid());
    exit(0);
  } else {
    printf("Running Parent, PID = %d", getpid());
    while (1) {
      ;
    }
  }
}

void fork8() {
  if (fork() == 0) {
    printf("Running Child, PID = %d\n", getpid());
    while (1) {
      ;
    }
  } else {
    printf("Terminating Parent, PID = %d\n", getpid());
    exit(0);
  }
}

void fork9() {
  int child_status;

  if (fork() == 0) {
    printf("HC: hello from child\n");
    exit(0);
  } else {
    printf("HP: hello from parent\n");
    wait(&child_status);
    printf("CT: Child has terminated\n");
  }
  printf("Bye\n");
}

void fork10() {
  pid_t pid[N];
  int i, child_status;

  for (i = 0; i < N; ++i) {
    if ((pid[i] = fork()) == 0) {
      exit(100 + i);
    }
  }

  for (i = 0; i < N; ++i) {
    pid_t wpid = wait(&child_status);
    if (WIFEXITED(child_status)) {
      printf("Child %d terminated with exit status %d\n", wpid,
             WEXITSTATUS(child_status));
    } else {
      printf("Child %d terminated abnormally\n", wpid);
    }
  }
}

void fork11() {
  pid_t pid[N];
  int i, child_status;

  for (i = 0; i < N; ++i) {
    if ((pid[i] = fork()) == 0) {
      exit(100 + i);
    }
  }

  // for (i = 0; i < N; ++i) {
  for (i = N - 1; i >= 0; --i) {
    pid_t wpid = waitpid(pid[i], &child_status, 0);
    if (WIFEXITED(child_status)) {
      printf("Child %d terminated with exit status %d\n", wpid,
             WEXITSTATUS(child_status));
    } else {
      printf("Child %d terminated abnormally\n", wpid);
    }
  }
}

void fork12() {
  pid_t pid[N];
  int child_status;

  for (int i = 0; i < N; ++i) {
    if ((pid[i] = fork()) == 0) {
      while (1) {
        ;
      }
    }
  }

  for (int i = 0; i < N; ++i) {
    printf("Killing process %d\n", pid[i]);
    kill(pid[i], SIGINT);
  }

  for (int i = 0; i < N; ++i) {
    pid_t wpid = wait(&child_status);
    if (WIFEXITED(child_status)) {
      printf("Child %d terminated with status %d\n", wpid, child_status);
    } else {
      printf("Child %d terminated abnormally\n", wpid);
    }
  }
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    printf("Usage: %s <number>\n", argv[0]);
    exit(1);
  }

  int n = atoi(argv[1]);
  switch (n) {
    case 7:
      fork7();
      break;
    case 8:
      fork8();
      break;
    case 9:
      fork9();
      break;
    case 10:
      fork10();
      break;
    case 11:
      fork11();
      break;
    case 12:
      fork12();
      break;
    default:
      puts("Invalid fork number");
      exit(1);
  }

  return 0;
}
