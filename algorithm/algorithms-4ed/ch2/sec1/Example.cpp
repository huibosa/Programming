#include <iostream>
#include <vector>
#include <cassert>

class Example {
public:
  void sort(std::vector<int>& nums);
  bool isSorted(const std::vector<int>& nums) const;
  void show(const std::vector<int>& nums) const;
private:
  bool less(int v, int w) const;
  void exch(std::vector<int>& nums, int i, int j);
};

inline void Example::exch(std::vector<int>& nums, int i, int j) {
  auto tmp = nums[i];
  nums[i] = nums[j];
  nums[j] = tmp;
}

inline void Example::show(const std::vector<int>& nums) const {
  for (int i = 0; i < nums.size(); ++i) {
    std::cout << nums[i] << " ";
  }
  std::cout << "\n";
};

inline bool Example::less(int v, int w) const {
  return v < w;
};

inline bool Example::isSorted(const std::vector<int>& nums) const {
  for (int i = 0; i < nums.size(); ++i) {
    if (less(nums[i], nums[i-1])) {
      return false;
    }
  }
  return true;;
}

int main() {
  std::vector<int> nums;
  for (auto temp = 0; std::cin >> temp;) {
    nums.push_back(temp);
  }

  Example exa;
  exa.sort(nums);
  assert(exa.isSorted(nums));
  exa.show(nums);

  return 0;
}
