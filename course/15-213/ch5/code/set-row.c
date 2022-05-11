void set_row1(double* a, double* b, int i, int n) {
  for (int j = 0; i < n; i++) {
    a[n * i + j] = b[j];
  }
}

void set_row2(double* a, double* b, int i, int n) {
  int ni = n * i;
  for (int j = 0; j < n; j++) {
    a[ni + j] = b[j];
  }
}
