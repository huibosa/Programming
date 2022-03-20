#pragma once

#include <iostream>
#include <vector>
#include <cassert>

template<typename _Tp>
class ShellSortWithCompareCount {
public:
  void sort(std::vector<_Tp>& a);
  bool isSorted(const std::vector<_Tp>& a);
  void show(const std::vector<_Tp>& a) const;
  int getCompareCount() const { return compareCount; }
private:
  bool less(_Tp v, _Tp w);
  void exch(std::vector<_Tp>& a, int i, int j);
private:
  int compareCount = 0;
};

template<typename _Tp>
inline void ShellSortWithCompareCount<_Tp>::exch(std::vector<_Tp>& a, int i, int j) {
  auto tmp = a[i];
  a[i] = a[j];
  a[j] = tmp;
}

template<typename _Tp>
inline void ShellSortWithCompareCount<_Tp>::show(const std::vector<_Tp>& a) const {
  for (int i = 0; i < a.size(); ++i) {
    std::cout << a[i] << " ";
  }
  std::cout << "\n";
};

template<typename _Tp>
inline bool ShellSortWithCompareCount<_Tp>::less(_Tp v, _Tp w) {
  ++compareCount;
  return v < w;
};

template<typename _Tp>
inline bool ShellSortWithCompareCount<_Tp>::isSorted(const std::vector<_Tp>& a) {
  for (int i = 0; i < a.size(); ++i) {
    if (less(a[i], a[i-1])) {
      return false;
    }
  }
  return true;;
}

template<typename _Tp>
inline void ShellSortWithCompareCount<_Tp>::sort(std::vector<_Tp>& a) {
  auto n = a.size();
  
  // or store increment sequence in an array
  auto h = 1;
  while (h < n/3) {
    h = 3 * h + 1;
  }

  while (h >= 1) {
    for (int i = h; i < n; ++i) {
      for (int j = i; j >= h && less(a[j], a[j-h]); j -= h) {
        exch(a, j, j-h);
      }
    }
    h /= 3;
  }
};
