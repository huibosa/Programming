#include <string>
#include <vector>
#include "inc/Insertion.h"

std::vector<std::string> dedup(const std::vector<std::string>& a) {
  auto ret = a;
  Insertion<std::string> insertion;
  insertion.sort(ret);

  for (auto itr = ret.begin(); itr != ret.end();) {
    if (*itr == *(itr+1)) {
      ret.erase(itr+1);
    } else {
      ++itr;
    }
  }

  return ret;
}

int main() {
  std::vector<std::string> strs{"bv", "as", "eg", "qe", "as", "eg", "he"};

  auto res = dedup(strs);

  for (const auto& str : res) {
    std::cout << str << " ";
  }

  return 0;
}
