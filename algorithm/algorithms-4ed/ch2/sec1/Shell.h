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
  
  auto h = 1;
  while (h < n/3) {
    h = 3 * h + 1;
  }

  while (h >= 1) {
    for (int i = h; i < n; ++i) {
      for (int j = i; j >= i && less(a[j], a[j-h]); j -= h) {
        exch(a, j, j-h);
      }
    }
    h /= 3;
  }
};
