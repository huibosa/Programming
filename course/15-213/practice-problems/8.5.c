#include <csapp.h>

unsigned int snooze(unsigned int secs) {
  unsigned int rc = sleep(secs);
  printf("Slept for %d of %d secs.\n", secs - rc, secs);
  return rc;
}

int main(void) {
  snooze(3);

  return 0;
}
