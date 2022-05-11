int sum_neighbor1(int* val, int n, int i, int j) {
  int up, down, left, right, sum;

  up    = val[(i - 1) * n + j];
  down  = val[(i + 1) * n + j];
  left  = val[n * i + j - 1];
  right = val[n * i + j + 1];
  sum   = up + down + left + right;

  return sum;
}

int sum_neighbor2(int* val, int n, int i, int j) {
  int up, down, left, right, sum;

  int inj = i * n + j;
  up      = val[inj - n];
  down    = val[inj + n];
  left    = val[inj - 1];
  right   = val[inj + 1];
  sum     = up + down + left + right;

  return sum;
}
