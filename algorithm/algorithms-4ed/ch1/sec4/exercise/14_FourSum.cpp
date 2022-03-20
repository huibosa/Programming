#include <algorithm>
#include <iostream>
#include <memory>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <list>

int fourSum(const std::vector<int>& vals) {
  std::unordered_map<int, std::list<std::pair<int, int>>> sumMap;

  for (int i = 0; i < vals.size(); ++i) {
    for (int j = i + 1; j < vals.size(); ++j) {
      auto sum = vals[i] + vals[j];

      if (sumMap.find(sum) == sumMap.end()) {
        std::list<std::pair<int, int>> newList;
        sumMap[sum] = newList;
      }
      auto newPair = std::make_pair(i, j);
      sumMap[sum].push_back(newPair);
    }
  }

  auto retval = 0;

  for (const auto& item : sumMap) {
    if (sumMap.find(-item.first) != sumMap.end()) {
      auto pairs = item.second;
      auto pairsComplement = sumMap[-item.first];

      for (const auto& pair1 : pairs) {
        for (const auto& pair2 : pairsComplement) {
          if (pair1.second < pair2.first) {
            retval++;
            std::cout << retval << "\n";
          }
        }
      }
    }
  }

  return retval;
}

int fourSum2(const std::vector<int>& vals) {
  auto vec = vals;

  std::sort(vec.begin(), vec.end());

  auto retval = 0;

  for (int i = 0; i < vec.size(); ++i) {
    for (int j = i + 1; j < vec.size(); ++j) {
      for (int k = j + 1; k < vec.size(); ++k) {
        int searchElement = -(vec[i] + vec[j] + vec[k]);
      }
    }
  }
}


int main() {
#if 0
  std::vector<int> v1{5, 2, -2, -5, -2};
  std::vector<int> v2{1, 2, 3, 4, -4, -5, -6, 2, 4, -1};

  std::cout << "Method 1" << "\n";
  std::cout << "4 sum: " << fourSum(v1) << "\n";
  std::cout << "Expected: 2" << "\n";

  std::cout << "4 sum: " << fourSum(v2) << "\n";
  std::cout << "Expected: 13" << "\n";

  /* std::cout << "Method 2" << "\n"; */
  /* std::cout << "4 sum: " << fourSum2(v1) << "\n"; */
  /* std::cout << "Expected: 2" << "\n"; */

  /* std::cout << "4 sum: " << fourSum2(v2) << "\n"; */
  /* std::cout << "Expected: 13" << "\n"; */
#endif

#if 1
  std::vector<int> val;
  auto temp = 0;
  while (std::cin >> temp) {
    val.push_back(temp);
  }
  std::cout << fourSum(val) << "\n";

  return 0;
#endif
}
