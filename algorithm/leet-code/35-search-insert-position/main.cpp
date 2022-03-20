#include "./35-serch-insert-position.h"
#include <iostream>
#include <vector>

int main() {
  Solution sln;

  std::vector<int> nums{1, 3, 5, 6};
  auto target = 5;

  auto res = sln.searchInsert(nums, target);

  std::cout << res << "\n";

  return 0;
}
