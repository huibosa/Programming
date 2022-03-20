long fact_while_gd_goto(long n) {
  long ret = 1;
  if (n <= 1)
    goto done;
loop:
  ret *= n;
  n--;
  if (n != 1) {
    goto loop;
  }
done:
  return ret;
}
