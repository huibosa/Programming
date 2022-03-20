/* 1.1.17 Criticize the following recursive function: */

#include <string>

std::string exR2(int n) {
  std::string s = exR2(n - 3) + std::to_string(n) + exR2(n - 2) + std::to_string(n);
  if (n <= 0) {
    return "";
  }
  return s;
}
