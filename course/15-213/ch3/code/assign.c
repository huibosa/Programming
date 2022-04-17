#include <stdio.h>

typedef unsigned char src_t;
typedef long dest_t;

void assign(src_t * sp, dest_t * dp) {
  *dp = (dest_t) *sp;
}
