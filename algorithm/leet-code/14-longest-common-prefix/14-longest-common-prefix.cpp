#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
  std::string longestCommonPrefix(std::vector<std::string> &strs) {
    std::string ret = strs[0];

    for (const auto &s : strs) {
      if (ret == s) {
        continue;
      }

      for (int i = 0; i < ret.size(); ++i) {
        if (ret[i] != s[i]) {
          ret = s.substr(0, i);
        }
      }
    }
    return ret;
  }
  std::string longestCommonPrefix2(std::vector<std::string> &strs) {
    std::string word;

    if (strs.size() <= 0) {
      return word;
    }

    for (int i = 0; i <= strs[0].size(); ++i) {
      std::string w = strs[0].substr(0, i);
      bool match = true;
      int j = 1;
      for (j = 1; j < strs.size(); ++j) {
        if (i > strs[j].size() || w != strs[j].substr(0, i)) {
          match = false;
          break;
        }
      }
      if (!match) {
        return word;
      }
      word = w;
    }
    return word;
  }
};

int main() {
  Solution sln;
  std::vector<std::string> strs{"flower", "flow", "flight"};
  std::string s = sln.longestCommonPrefix(strs);

  std::cout << s << std::endl;
}
