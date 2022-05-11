// Sum rows is of n * n matrix a and store in vector b
void sum_row1(double* a, double* b, long n) {
  for (int i = 0; i < n; i++) {
    b[i] = 0;
    for (int j = 0; j < n; j++) {
      b[i] += a[n * i + j];
    }
  }
}

void sum_row2(double* a, double* b, long n) {
  for (int i = 0; i < n; i++) {
    double val;
    for (int j = 0; j < n; j++) {
      val += a[n * i + j];
    }
    b[i] += val;
  }
}
