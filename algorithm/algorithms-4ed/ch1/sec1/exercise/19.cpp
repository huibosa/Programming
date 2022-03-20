// Run the following program on your computer

/* What is the largest value of N for which this program takes less 1 hour to compute the */
/* value of F(N)? Develop a better implementation of F(N) that saves computed values in */
/* an array. */

#include <iostream>
#include <iterator>
#include <memory>
#include <vector>

#define MAX 10000

auto recursion(int n) {
  if (n == 0) { return 0; }
  else if (n == 1) { return 1; }

  return recursion(n - 1) + recursion(n - 2);
}

auto recurence(int n) {
  auto pa = new long[n]();

  pa[0] = 0;
  pa[1] = 1;

  for (int i = 2; i < n; ++i) {
    pa[i] = pa[i-1] + pa[i-2];
  }
  return pa;
}

int main() {
  for (int i = 2; i < 50; ++i) {
    auto result = recurence(i);

    std::cout << '[' <<  i-1 << ']' << '\t'
              <<  result[i-1] << std::endl;

    delete result;
  }

  return 0;
}
