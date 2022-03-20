#ifndef ORDERED_LIST_PQ_H
#define ORDERED_LIST_PQ_H


#include "inc/List.h"

template <typename _Tp> class MaxPQ {
public:
  void insert(_Tp item) { pq.push_back(item); }
  _Tp delMax();
  size_t size() const { return pq.size(); };
  bool empty() const { return size() == 0; };
private:
  List<_Tp> pq;
};

template <typename _Tp> _Tp MaxPQ<_Tp>::delMax() {
  
}

#endif /* ORDERED_LIST_PQ_H */
