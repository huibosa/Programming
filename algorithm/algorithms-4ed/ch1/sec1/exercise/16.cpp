// Give the value of exR1(6):

#include <iostream>
#include <string>

std::string exR1(int n) {
  if (n <= 0) {
    return "";
  }
  return exR1(n - 3) + std::to_string(n) + exR1(n - 2) + std::to_string(n);
}


int main() {

  std::cout << exR1(6) << "\n";

  return 0;
}
