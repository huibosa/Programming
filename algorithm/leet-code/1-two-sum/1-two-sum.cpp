#include <algorithm>
#include <iostream>
#include <iterator>
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<int> twoSum1(std::vector<int> &nums, int target) {
    std::unordered_map<int, int> m;
    std::vector<int> retval;

    for (int i = 0; i < nums.size(); ++i) {
      if (m.find(nums[i]) == m.end()) {
        m[target - nums[i]] = i;
      } else {
        retval.push_back(m[nums[i]] + 1);
        retval.push_back(m[nums[i]]);
        return retval;
      }
    }
    retval.push_back(-1);
    retval.push_back(-1);
    return retval;
  }

  std::vector<int> twoSum2(std::vector<int> &nums, int target) {
    std::unordered_map<int, int> m;

    for (int i = 0; i < nums.size(); ++i) {
      if (m.find(target - nums[i]) == m.end()) {
        m[nums[i]] = i;
      } else {
        return std::vector<int>{m[target - nums[i]], i};
      }
    }
    return std::vector<int>{-1, -1};
  }
};

int main() {
  Solution sln;
  std::vector<int> a{1, 3, 7, 5};
  auto res = sln.twoSum2(a, 10);

  std::for_each(res.begin(), res.end(),
                [](const int &i) { std::cout << i << " "; });

  return 0;
}
