#ifndef SHUFFLE_H
#define SHUFFLE_H

#include <list>


template <typename _Tp> class Shuffle {
public:
  void shuffle(std::list<_Tp> &);

private:
  void shuffle(std::list<_Tp> &, std::list<_Tp> &, int lo, int hi);
  void merge(std::list<_Tp> &, std::list<_Tp> &, int lo, int mid, int hi);
};


template <typename _Tp> void Shuffle<_Tp>::shuffle(std::list<_Tp> &a) {
  std::list<_Tp> aux;
  shuffle(a, aux, 0, a.size());
}


template <typename _Tp>
void Shuffle<_Tp>::shuffle(std::list<_Tp> &a, std::list<_Tp> &aux, int lo,
                           int hi) {
  if (hi <= lo) {
    return;
  }

  auto mid = lo + (hi - lo) / 2;
  shuffle(a, aux, lo, mid);
  shuffle(a, aux, mid + 1, hi);
  merge(a, aux, lo, mid, hi);
}


template <typename _Tp>
void Shuffle<_Tp>::merge(std::list<_Tp> &a, std::list<_Tp> &aux, int lo,
                         int mid, int hi) {
  
}

#endif /* SHUFFLE_H */
