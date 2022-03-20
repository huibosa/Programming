#include <cstdlib>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error_functions.h"
#include "tlpi_hdr.h"
#include "ename.c.inc"

#ifdef __GNUC__
__attribute__ ((__noreturn__))
#endif

static void terminate(Boolean useExit3) {
  char * s;

  /* Dump core if EF_DUMPCORE environment variable is defined and
  is a nonempty string; otherwise call exit(3) or _exit(2),
  depending on the value of 'useExit3'. */

  s = getenv("EF_DUMPCORE");

  if (s != NULL && *s != '\0') {
    abort();
  } else if (useExit3) {
    exit(EXIT_FAILURE);
  } else {
    _exit(EXIT_FAILURE);
  }
}

static void outputError(Boolean useErr, int err, Boolean flushStdOut,
                        const char * format, va_list ap) {
#define BUF_SIZE 500
  char buf[BUF_SIZE];
  char userMsg[BUF_SIZE];
  char errText[BUF_SIZE];

  vsnprintf(userMsg, BUF_SIZE, format, ap);

  if (useErr) {
    snprintf(errText, BUF_SIZE, " [%s %s]",
            (err > 0 && err <= MAX_NAME) ? ename[err] : "?UNKNOWN",
            strerror(err));
  } else {
    snprintf(errText, BUF_SIZE, ":");
  }
  
  snprintf(buf, BUF_SIZE, "ERROR%s %s\n", errText, userMsg);

  if (flushStdOut) {
    fflush(stdout);     /* Flush any pending stdout */
  }
  fputs(buf, stderr);
  fflush(stderr);       /* In case stderr is not line-buffered */
}
