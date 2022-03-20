#include <cstddef>
#include <iostream>
#include <unordered_map>
#include <memory>
#include <vector>
#include "RandomGenerator.h"

size_t TwoSumFaster(std::shared_ptr<std::vector<int>> pv) {
  std::unordered_map<size_t, size_t> hashMap;

  for (const auto& i : *pv) {
    if (hashMap.find(0 - i) == hashMap.end()) {
      hashMap[-i] = 0;
    } else {
      hashMap[-i]++;
    }
  }

  size_t count = 0;

  for (const auto& item : hashMap) {
    if (item.second > 0) {
      count++;
    }
  }

  return count;
}

int main() {
  RandomGenerator rg(1000);
  auto pv(rg.getPointer());

  auto res = TwoSumFaster(pv);

  std::cout << res << "\n";

  return 0;
}
