// jump to middle
long fact_while_jm_goto(long n) {
  long ret = 1;
  goto test;
loop:
  ret *= n;
  n--;
test:
  if (n > 1)
    goto loop;
  return ret;
}
