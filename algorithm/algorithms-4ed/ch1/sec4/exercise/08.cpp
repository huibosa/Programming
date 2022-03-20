#include <iostream>
/* 1.4.8 Write a progrm to determine the number pairs of values in an input file */
/* that are equal. If your first try is quadratic, think again and use */
/* Arrays.sort() to develop a linearithmic solution.a */

#include <cstddef>
#include <iostream>
#include <iterator>
#include <memory>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>

int countEqualPairs1(std::vector<size_t>& vals) {
  std::unordered_map<size_t, int> hash;
  int ret = 0;

  for (const auto& val : vals) {
    hash[val]++;
  }

  for (const auto& item : hash) {
    if (item.second > 1) {
      ret++;
    }
  }

  return ret;
}

int countEqualPairs2(std::vector<size_t>& vals) {
  std::sort(vals.begin(), vals.end());

  int ret = 0;
  bool pairStart = false;

  for (int i = 1; i < vals.size(); ++i) {
    if (vals[i] == vals[i-1]) {
      if (!pairStart) {
        ret++;
        pairStart = true;
      }
    }
    else {
      pairStart = false;
    }
  }
  return ret;
}

int main() {
  std::vector<size_t> vals;

  for (size_t temp = 0; std::cin >> temp; ) {
    vals.push_back(temp);
  }

  auto res = countEqualPairs1(vals);
  /* std::cout << res << "\n"; */

  return 0;
}
