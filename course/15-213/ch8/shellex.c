#include <csapp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#define MAXARGS 28

void eval(char* cmdline);
int parseline(char* buf, char** argv);
int builtin_command(char** argv);

int main(void) {
  char cmdline[MAXLINE];

  while (1) {
    printf("> ");
    Fgets(cmdline, MAXLINE, stdin);
    if (feof(stdin)) {
      exit(0);
    }
    eval(cmdline);
  }

  return 0;
}

void eval(char* cmdline) {
  char* argv[MAXARGS];
  char buf[MAXLINE];
  int bg;
  pid_t pid;

  strcpy(buf, cmdline);
  bg = parseline(buf, argv);
  if (argv[0] == NULL) {
    return;  // ignore empty lines
  }

  if (!builtin_command(argv)) {
    if ((pid = Fork()) == 0) {
      if ((execve(argv[0], argv, environ)) < 0) {
        printf("%s: Command not found.\n", argv[0]);
        exit(0);
      }
    }

    if (!bg) {
      int status;
      if ((waitpid(pid, &status, 0)) < 0) {
        unix_error("waitfg: waitpid error");
      }
    } else {
      printf("%d %s", pid, cmdline);
    }
  }
  return;
}

int builtin_command(char** argv) {
  if (!strcmp(argv[0], "quit")) {  // builin quit command
    exit(0);
  }
  if (!strcmp(argv[0], "&")) {  // any command other than a singleton &
    return 1;
  }
  return 0;
}

int parseline(char* buf, char** argv) {
  int argc = 0;
  int buflen;

  buf[strlen(buf) - 1] = ' ';      // replace trailing '\n' to space
  while (*buf && (*buf == ' ')) {  // ignore leading spaces
    buf++;
  }

  buflen = strlen(buf);
  for (int p = 0, q = 0; p < buflen && q < buflen;) {
    if (buf[q] != ' ') {
      q++;
      continue;
    }
    buf[q] = '\0';
    argv[argc++] = buf + p;
    p = q + 1;
  }

  // Check if run in background
  if (!strcmp(argv[argc - 1], "&")) {
    return 1;
  } else {
    return 0;
  }
}

// int parseline(char* buf, char** argv) {
//   char* delim; /* Points to first space delimiter */
//   int argc;    /* Number of args */
//   int bg;      /* Background job? */

//   buf[strlen(buf) - 1] = ' ';   /* Replace trailing '\n' with space */
//   while (*buf && (*buf == ' ')) /* Ignore leading spaces */
//     buf++;

//   /* Build the argv list */
//   argc = 0;
//   while ((delim = strchr(buf, ' '))) {
//     argv[argc++] = buf;
//     *delim = '\0';
//     buf = delim + 1;
//     while (*buf && (*buf == ' ')) /* Ignore spaces */
//       buf++;
//   }
//   argv[argc] = NULL;

//   if (argc == 0) /* Ignore blank line */
//     return 1;

//   /* Should the job run in the background? */
//   if ((bg = (*argv[argc - 1] == '&')) != 0) argv[--argc] = NULL;

//   return bg;
// }
