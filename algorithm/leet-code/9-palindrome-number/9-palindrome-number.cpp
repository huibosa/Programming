#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
  bool isPalindrome1(int x) {
    if (x < 0) {
      return false;
    }
    if (x > 0 && x % 10 == 0) {
      return false;
    }

    auto reverse = 0;
    while (x > reverse) {
      reverse = reverse * 10 + x % 10;
      x /= 10;
    }

    return x == reverse || x == reverse / 10;
  }

  bool isPalindrome2(int x) {
    auto str = std::to_string(x);

    if (str.empty()) {
      return false;
    }

    for (auto iter1 = str.cbegin(), iter2 = str.cend() - 1; iter1 != iter2;
         ++iter1, --iter2) {
      if (*iter1 != *iter2) {
        return false;
      }
      if (iter1 + 1 == iter2) {
        break;
      }
    }
    return true;
  }
  bool isPalindrome3(int x) {
    auto str = std::to_string(x);
    auto rstr(str);

    if (str.empty()) {
      return false;
    }

    std::reverse(str.begin(), str.end());

    if (str == rstr) {
      return true;
    } else {
      return false;
    }
  }
};

int main() {
  Solution sln;

  if (sln.isPalindrome1(121)) {
    std::cout << "true" << std::endl;
  }
}
