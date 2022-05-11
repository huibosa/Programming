double poly(double a[], double x, long degree) {
  long ret  = a[0];
  long xpwr = x;

  for (long i = 1; i <= degree; i++) {
    ret += a[i] * xpwr;
    xpwr = x * xpwr;
  }

  return ret;
}
