void minmax0(long a[], long b[], long n) {
  for (long i = 0; i < n; i++) {
    if (a[i] > b[i]) {
      long t = a[i];
      a[i] = b[i];
      b[i] = t;
    }
  }
}

void minmax1(long a[], long b[], long n) {
  for (long i = 0; i < n; i++) {
    long min = a[i] < b[i] ? a[i] : b[i];
    long max = a[i] > b[i] ? a[i] : b[i];
    a[i] = min;
    b[i] = max;
  }
}
