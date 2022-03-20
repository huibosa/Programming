/* 2.1.11  Implement a version of shellsort that keeps the increment sequence in an array, */ 
/* rather than computing it. */

#pragma once

#include <iostream>
#include <vector>
#include <cassert>

template<typename _Tp>
class Shell {
public:
  void sort(std::vector<_Tp>& a);
  bool isSorted(const std::vector<_Tp>& a) const;
  void show(const std::vector<_Tp>& a) const;
private:
  bool less(_Tp v, _Tp w) const;
  void exch(std::vector<_Tp>& a, int i, int j);
};

template<typename _Tp>
inline void Shell<_Tp>::exch(std::vector<_Tp>& a, int i, int j) {
  auto tmp = a[i];
  a[i] = a[j];
  a[j] = tmp;
}

template<typename _Tp>
inline void Shell<_Tp>::show(const std::vector<_Tp>& a) const {
  for (int i = 0; i < a.size(); ++i) {
    std::cout << a[i] << " ";
  }
  std::cout << "\n";
};

template<typename _Tp>
inline bool Shell<_Tp>::less(_Tp v, _Tp w) const {
  return v < w;
};

template<typename _Tp>
inline bool Shell<_Tp>::isSorted(const std::vector<_Tp>& a) const {
  for (int i = 0; i < a.size(); ++i) {
    if (less(a[i], a[i-1])) {
      return false;
    }
  }
  return true;;
}

template<typename _Tp>
inline void Shell<_Tp>::sort(std::vector<_Tp>& a) {
  auto n = a.size();
  std::vector<int> incr;

  for (auto h = 1; h * 3 + 1 <= n; h = h * 3 + 1) {
    incr.push_back(h);
  }

  for (auto r = incr.rbegin(); r != incr.rend(); ++r) {
    for (int i = *r; i < n; ++i) {
      for (int j = i; j >= *r && less(a[j], a[j - *r]); j -= *r) {
        exch(a, j, j - *r);
      }
    }
  }
};
