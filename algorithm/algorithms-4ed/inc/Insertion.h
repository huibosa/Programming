#pragma once

#include <iostream>
#include <vector>
#include <cassert>

template<typename _Tp> class MergeImprove;
template<typename _Tp> class QuickInsertion;

template<typename _Tp> class Insertion {
  friend class MergeImprove<_Tp>;
  friend class QuickInsertion<_Tp>;
public:
  void sort(std::vector<_Tp>& a);
  bool isSorted(const std::vector<_Tp>& a) const;
  void show(const std::vector<_Tp>& a) const;
private:
  void sort(std::vector<_Tp>& a, int lo, int hi);
  bool less(_Tp v, _Tp w) const;
  void exch(std::vector<_Tp>& a, int i, int j);
};

template<typename _Tp>
inline void Insertion<_Tp>::exch(std::vector<_Tp>& a, int i, int j) {
  auto tmp = a[i];
  a[i] = a[j];
  a[j] = tmp;
}

template<typename _Tp>
inline void Insertion<_Tp>::show(const std::vector<_Tp>& a) const {
  for (int i = 0; i < a.size(); ++i) {
    std::cout << a[i] << " ";
  }
  std::cout << "\n";
};

template<typename _Tp>
inline bool Insertion<_Tp>::less(_Tp v, _Tp w) const {
  return v < w;
};

template<typename _Tp>
inline bool Insertion<_Tp>::isSorted(const std::vector<_Tp>& a) const {
  for (int i = 0; i < a.size(); ++i) {
    if (less(a[i], a[i-1])) {
      return false;
    }
  }
  return true;;
}

template<typename _Tp> inline void Insertion<_Tp>::sort(std::vector<_Tp>& a) {
  sort(a, 0, a.size() - 1);
}

template<typename _Tp>
inline void Insertion<_Tp>::sort(std::vector<_Tp>& a, int lo, int hi) {
  for (int i = lo; i <= hi; ++i) {
    for (int j = i; j > lo && less(a[j], a[j-1]); --j) {
      exch(a, j, j-1);
    }
  }
};
