long absdiff(long x, long y) {
  long result;
  if (x < y) {
    result = y - x;
  } else {
    result = x - y;
  }
  return result;
}

long cmovdiff(long x, long y) {
  long rval = y - x;
  long eval = x - y;
  long ntest = x >= y;
  if (ntest) {
    rval = eval;
  }
  return rval;
}
