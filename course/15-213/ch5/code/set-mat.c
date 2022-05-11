void set_mat1(double* a, double* b, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      a[n * i + j] = b[j];
    }
  }
}

void set_mat2(double* a, double* b, int n) {
  int ni = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      a[n * i + j] = b[j];
    }
    ni += i;
  }
}
