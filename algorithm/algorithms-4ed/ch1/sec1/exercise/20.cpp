// Write a recursive static method that computes the value of ln(N!)

#include <iostream>
#include <cmath>

long factResursion(int n) {
  if (n == 0) { return 1; }
  return n * factResursion(n-1);
}

auto factResurrence(int n) {
  auto pa = new long[n+1]();

  pa[0] = 1;
  for (int ix = 1; ix <= n; ++ix) {
    pa[ix] = pa[ix-1] * ix;
  }

  return pa;
}

auto ln(long n) {
  /* auto f = factResursion(n); */
  auto facts = factResurrence(n);
  auto f = facts[n];
  delete [] facts;

  auto ret = 0;
  for (; f > 1; f /= std::exp(1)) {
    ret++;
  }
  return ret;
}

int main() {
  while (true) {
    std::cout << ln(20) << std::endl;
  }
}
