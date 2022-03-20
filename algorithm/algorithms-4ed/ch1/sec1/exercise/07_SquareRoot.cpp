/* Give the value printed by each of the following code fragments: */

#include <cstdlib>
#include <iostream>
#include <cmath>

void testA() {
  double t = 2.0;
  while (std::abs(t - 2.0/t) > .001) {
    t = (2.0/t + t) / 2.0;
    std::cout << t << "\n";
  }
  printf("%.5f\n", t);    // 3.00009
}

void testB() {
  int sum = 0;

  for (int i = 0; i < 1000; ++i) {
    for (int j = 0; j < i; ++j) {
      ++sum;
    }
  }
  std::cout << sum << "\n";
}

void testC() {
  int sum = 0;
  for (int i = 1; i < 1000; i *= 2) {
    for (int j = 0; j < i; ++j) {
      ++sum;
    }
  }
  std::cout << sum << "\n";
}

int main() {
  testA();
  /* testB(); */
  /* testC(); */
  

  return 0;
}
