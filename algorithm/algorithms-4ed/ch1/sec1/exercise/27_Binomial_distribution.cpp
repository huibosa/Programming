/* 1.1.27 Binomial distribution. Estimate the number of recursive calls that would be */
/* used by the code */
  // public static double binomial(int N, int k, double p)
  // {
  // if ((N == 0) || (k < 0)) return 1.0;
  // return (1.0 - p)*binomial(N-1, k) + p*binomial(N-1, k-1);
  // }
/* to compute binomial(100, 50). Develop a better implementation that is based on */


#include <cstddef>
#include <iostream>

std::size_t count = 0;

double binomial1(int n, int k, double p = 0) {
  if (n == 0 || k == 0) { return 1.0; }
  if (n < 0 || k < 0) { return 0.0; }

  count++;
  return (1.0 - p) * binomial1(n-1, k) + p * binomial1(n-1, k-1);
}

int main() {
  std::cout << binomial1(10, 1, 0.9) << std::endl;
}
