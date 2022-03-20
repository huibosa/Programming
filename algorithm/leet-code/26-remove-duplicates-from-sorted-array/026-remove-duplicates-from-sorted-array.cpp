#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

class Solution {
public:
  int removeDuplicates1(std::vector<int> &nums) {
    auto pivot = 0;
    auto cnt = nums.size();

    if (nums.size() == 0) {
      return 0;
    }

    if (nums.size() == 1) {
      return 1;
    }

    if (nums.size() == 2) {
      return (nums[0] == nums[1] ? 1 : 2);
    }

    for (auto iter = nums.begin(); cnt > 1; cnt--) {
      if (*iter == *(iter + 1)) {
        auto temp = *iter;
        iter = nums.erase(iter, iter + 1);
        nums.push_back(temp);
      } else {
        iter++;
        pivot++;
      }
    }
    pivot++;
    return pivot;
  }

  int removeDuplicates2(std::vector<int> &nums) {
    auto n = nums.size();
    if (n == 0) {
      return 0;
    }

    auto fast = 1; // iterate array
    auto slow = 1; // point to first duplicate item
    for (; fast < n; ++fast) {
      if (nums[fast] != nums[slow - 1]) {
        nums[slow] = nums[fast];
        ++slow;
      }
    }
    return slow;
  }
};

int main() {
  Solution sln;
  /* std::vector<int> nums{1,2,2}; */
  /* std::vector<int> nums{1,1,2}; */
  /* std::vector<int> nums{1,1,2,2,2,2}; */
  std::vector<int> nums{1, 1, 2, 2, 3, 4};

  auto pivot = sln.removeDuplicates2(nums);
  for (const auto &i : nums) {
    std::cout << i << " ";
  }

  std::cout << "\n";
  std::cout << pivot << "\n";

  return 0;
}
