long lt_cnt = 0;
long ge_cnt = 0;

long absdiff_se(long x, long y) {
  long result;
  if (x < y) {
    lt_cnt++;
    result = y - x;
  } else {
    ge_cnt++;
    result = x - y;
  }
  return result;
}

long gotodiff_se(long x, long y) {
  long result;
  if (x >= y) {
    goto x_ge_y;
  }
  lt_cnt++;
  result = y - x;
  return result;
x_ge_y:
  ge_cnt++;
  result = x - y;
  return result;
}

long gotdiff_se2(long x, long y) {
  long result;
  if (x < y) {
    goto x_l_y;
  }
  ge_cnt++;
  result = x - y;
x_l_y:
  lt_cnt++;
  result = y - x;
  return result;
}
