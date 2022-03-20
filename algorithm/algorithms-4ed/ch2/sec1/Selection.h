#pragma once

#include <iostream>
#include <vector>
#include <cassert>

template<typename _Tp>
class Selection {
public:
  void sort(std::vector<_Tp>& nums);
  bool isSorted(const std::vector<_Tp>& nums) const;
  void show(const std::vector<_Tp>& nums) const;
private:
  bool less(_Tp v, _Tp w) const;
  void exch(std::vector<_Tp>& nums, int i, int j);
};

template<typename _Tp>
inline void Selection<_Tp>::exch(std::vector<_Tp>& nums, int i, int j) {
  auto tmp = nums[i];
  nums[i] = nums[j];
  nums[j] = tmp;
}

template<typename _Tp>
inline void Selection<_Tp>::show(const std::vector<_Tp>& nums) const {
  for (int i = 0; i < nums.size(); ++i) {
    std::cout << nums[i] << " ";
  }
  std::cout << "\n";
};

template<typename _Tp>
inline bool Selection<_Tp>::less(_Tp v, _Tp w) const {
  return v < w;
};

template<typename _Tp>
inline bool Selection<_Tp>::isSorted(const std::vector<_Tp>& nums) const {
  for (int i = 0; i < nums.size(); ++i) {
    if (less(nums[i], nums[i-1])) {
      return false;
    }
  }
  return true;;
}

template<typename _Tp>
inline void Selection<_Tp>::sort(std::vector<_Tp>& nums) {
  auto n = nums.size();
  
  for (int i = 0; i < n; ++i) {
    auto min = i;
    for (int j = i + 1; j < n; ++j) {
      if (less(nums[j], nums[min])) {
        min = j;
      }
    }
    exch(nums, i, min);
  }
};
