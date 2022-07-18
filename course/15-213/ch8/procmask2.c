#include <asm-generic/errno-base.h>
#include <bits/types/sigset_t.h>
#include <csapp.h>
#include <errno.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

void initjobs();
void addjob(pid_t pid);
void deletejob(pid_t pid);

void handler(int sig) {
  pid_t pid;
  sigset_t mask_all, prev_all;
  int olderrno = errno;

  while ((pid = waitpid(-1, NULL, 0)) > 0) {
    Sigprocmask(SIG_BLOCK, &mask_all, &prev_all);
    deletejob(pid);
    Sigprocmask(SIG_SETMASK, &prev_all, NULL);
  }

  if (errno != ECHILD) {
    Sio_error("waitpid error");
  }
  errno = olderrno;
}

int main(int argc, char *argv[]) {
  pid_t pid;
  sigset_t mask_all, mask_one, prev_one;

  Sigfillset(&mask_all);
  Sigemptyset(&mask_one);
  Sigaddset(&mask_one, SIGCHLD);
  Signal(SIGCHLD, handler);
  initjobs();

  while (1) {
    Sigprocmask(SIG_BLOCK, &mask_one, &prev_one);
    if ((pid = Fork()) == 0) {
      Sigprocmask(SIG_SETMASK, &prev_one, NULL);
      Execve("/bin/date", argv, NULL);
    }

    Sigprocmask(SIG_BLOCK, &mask_all, NULL);
    addjob(pid);
    Sigprocmask(SIG_SETMASK, &prev_one, NULL);
  }

  return 0;
}
