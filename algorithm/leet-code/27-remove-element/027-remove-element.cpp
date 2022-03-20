#include <iostream>
#include <vector>

class Solution {
public:
  // just use foreach
  int removeElement1(std::vector<int> &nums, int val) {
    auto n = nums.size();
    auto left = 0;
    for (auto right = 0; right < n; ++right) {
      if (nums[right] != val) {
        nums[left] = nums[right];
        ++left;
      }
    }
    return left;
  }

  int removeElement2(std::vector<int> &nums, int val) {
    // left point to entry about to be assigned
    // right point to the entry being processed
    auto left = 0;
    for (auto right = nums.size(); left < right;) {
      if (nums[left] == val) {
        nums[left] = nums[right - 1];
        right--;
      } else {
        left++;
      }
    }
    return left;
  }
};

int main() {
  Solution sln;
  std::vector<int> nums{1, 2, 3, 4, 5};
  std::cout << sln.removeElement2(nums, 1) << "\n";

  for (const auto &i : nums) {
    std::cout << i << " ";
  }
  std::cout << "\n";

  return 0;
}
