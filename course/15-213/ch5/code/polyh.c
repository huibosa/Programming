double polyh(double a[], double x, long degree) {
  double ret = a[degree];

  for (long i = degree - 1; i >= 0; i--) {
    ret = a[i] + x * ret;
  }

  return ret;
}
