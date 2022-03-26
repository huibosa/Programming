long fact_do_goto(long n) {
  long ret = 1;
loop:
  ret *= n;
  n--;
  if (n > 1)
    goto loop;
  return ret;
}
