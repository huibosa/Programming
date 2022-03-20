// 1.1.2 Give the type and value of each of the following expressions:
//   a. (1 + 2.236)/2
//   b. 1 + 2 + 3 + 4.0
//   c. 4.1 >= 4
//   d. 1 + 2 + "3"

#include <iostream>
#include <cstdio>

int main() {
  printf("%f\n", (1 + 2.236) / 2);  // double
  printf("%f\n", 1 + 2 + 3 + 4.0);  // double
  printf("%d\n", 4.1 >= 4);         // bool
  std::cout << "3" + 1 + 2   << "\n";   // 

  return 0;
}
