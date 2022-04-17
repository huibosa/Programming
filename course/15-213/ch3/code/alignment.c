#include <stdio.h>

struct P1 {
  short i;
  int c;
  int *j;
  short *d;
} p1;

struct P2 {
  int i[2];
  char c[8];
  short s[4];
  long *j;
} p2;

struct P3 {
  long w[2];
  int *c[2];
} p3;

struct P4 {
  char w[16];
  char *c[2];
} p4;

struct P5 {
  struct P4 a[2];
  struct P1 t;
} p5;

struct P6 {
  int i;
  char c;
  int j;
  char d;
} p6;

struct P7 {
  int i;
  char c;
  char d;
  long j;
} p7;

struct P8 {
  short w[3];
  char c[3];
} p8;

struct P9 {
  short w[5];
  char *c[3];
} p9;

struct P10 {
  struct P8 a[2];
  struct P7 t;
} p10;

int main(void) {
  printf("P1: %zd\n", sizeof(p1));
  printf("P2: %zd\n", sizeof(p2));
  printf("P3: %zd\n", sizeof(p3));
  printf("P4: %zd\n", sizeof(p4));
  printf("P5: %zd\n", sizeof(p5));
  printf("P6: %zd\n", sizeof(p6));
  printf("P7: %zd\n", sizeof(p7));
  printf("P8: %zd\n", sizeof(p8));
  printf("P9: %zd\n", sizeof(p9));
  printf("P10: %zd\n", sizeof(p10));

  return 0;
}
