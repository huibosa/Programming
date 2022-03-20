// 1.1.1 Give the value of each of the following expressions:
//   a. ( 0 + 15 ) / 2
//   b. 2.0e-6 * 100000000.1
//   c.  true && false || true && true

#include <cstdio>
#include <iostream>

int main() {
  printf("%d\n", (0 + 15) / 2);
  printf("%lf\n", 2.0e-6 * 100000000.1);
  std::cout << (true && false || true && true) << "\n";

  return 0;
}
