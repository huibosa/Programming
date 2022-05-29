#define MAXELEMS 1024

long data[MAXELEMS];
double fcyc2(int(int, int), int, int, int);

// 4x4 unrolling
int test(int elems, int stride) {
  int i;
  int length = elems;
  int limit = length - stride;
  int acc0 = 0, acc1 = 0, acc2 = 0, acc3 = 0;
  int sx2 = stride * 2, sx3 = stride * 3, sx4 = stride * 4;

  for (i = 0; i < limit; i += sx4) {
    acc0 += data[i];
    acc1 += data[i + stride];
    acc2 += data[i + sx2];
    acc3 += data[i + sx3];
  }

  for (; i < length; i++) {
    acc0 += data[i];
  }

  return ((acc0 + acc1) + (acc2) + (acc3));
}

double run(int size, int stride, double Mhz) {
  double cycles;
  int elems = size / sizeof(double);

  // Warm the cache
  test(elems, stride);

  // get runnint time of test() in CPU cycles
  cycles = fcyc2(test, elems, stride, 0);

  //                        running time
  return (size / stride) / (cycles / Mhz);
}
