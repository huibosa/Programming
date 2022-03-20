long fact_for_jm_goto(long n) {
  long i = 2;
  long ret = 1;
  goto test;
loop:
  ret *= i;
  i++;
test:
  if (i <= n)
    goto loop;
  
  return ret;
}
