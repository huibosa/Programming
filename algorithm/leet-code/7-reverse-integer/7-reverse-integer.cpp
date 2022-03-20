#include <cstdint>
#include <iostream>

class Solution {
public:
  int reverse(int x) {
    int ret = 0;

    while (x != 0) {
      if (ret < INT32_MIN / 10 || ret > INT32_MAX / 10) {
        return 0;
      }
      int digit = x % 10;
      x /= 10;
      ret = ret * 10 + digit;
    }

    return ret;
  }
};

int main() {
  Solution sln;
  std::cout << sln.reverse(123) << std::endl;
}
