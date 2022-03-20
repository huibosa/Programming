#ifndef FASTER_MERGE_H
#define FASTER_MERGE_H

#include <vector>

template <typename _Tp> class FasterMerge {
public:
  void sort(std::vector<_Tp>& a);
private:
  void sort(std::vector<_Tp> &a, int lo, int hi);
  void merge(std::vector<_Tp> &a, int lo, int mid, int hi);

private:
  std::vector<_Tp> aux;
};


template <typename _Tp>
inline void FasterMerge<_Tp>::sort(std::vector<_Tp>& a) {
  aux.reserve(a.size());
  sort(a, 0, a.size() - 1);
}


template <typename _Tp>
void FasterMerge<_Tp>::sort(std::vector<_Tp>& a, int lo, int hi) {
  if (hi <= lo) { return; }

  auto mid = lo + (hi - lo) / 2;

  sort(a, lo, mid);
  sort(a, mid + 1, hi);
  merge(a, lo, mid, hi);
}


template <typename _Tp>
void FasterMerge<_Tp>::merge(std::vector<_Tp> &a, int lo, int mid, int hi) {
  auto auxIndex = lo;
  
  for (int i = lo; i <= mid; ++i) {
    aux[auxIndex] = a[i];
    auxIndex++;
  }
  
  for (int i = hi; i >= mid + 1; --i) {
    aux[auxIndex] = a[i];
    auxIndex++;
  }

  auto p = lo;
  auto q = hi;

  for (int i = lo; i <= hi; ++i) {
    if (aux[p] < aux[q]) {
      a[i] = aux[p++];
    } else {
      a[i] = aux[q--];
    }
  }
}


#endif /* FASTER_MERGE_H */
