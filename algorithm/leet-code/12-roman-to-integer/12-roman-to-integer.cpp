#include <string>
#include <unordered_map>

class Solution {
public:
  int romanToInt(std::string s) {
    if (s.size() < 0) {
      return 0;
    }

    auto retval = romanCharToInt(s[0]);
    for (int i = 1; i != s.size(); ++i) {
      auto prev = romanCharToInt(s[i - 1]);
      auto curr = romanCharToInt(s[i]);
      if (prev < curr) {
        retval = retval - prev + (curr - prev);
      } else {
        retval += curr;
      }
    }
    return retval;
  }

private:
  int romanCharToInt(char ch) {
    int d = 0;
    switch (ch) {
    case 'I':
      d = 1;
      break;
    case 'V':
      d = 5;
      break;
    case 'X':
      d = 10;
      break;
    case 'L':
      d = 50;
      break;
    case 'C':
      d = 100;
      break;
    case 'D':
      d = 500;
      break;
    case 'M':
      d = 1000;
      break;
    }
    return d;
  }
};
