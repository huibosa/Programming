#ifndef UNORDERED_LIST_PQ_H
#define UNORDERED_LIST_PQ_H


#include "List.h"
#include <cstddef>
#include <stdexcept>

template <typename _Tp> class MaxPQ {
public:
  void insert(_Tp item) { pq.push_back(item); }
  _Tp rmMax();
  size_t size() const { return pq.size(); };
  bool empty() const { return size() == 0; };
private:
  List<_Tp> pq;
};

template <typename _Tp> _Tp MaxPQ<_Tp>::rmMax() {
  if (empty()) {
    throw std::runtime_error("delMax underflow");
  }
  
  auto tempNode = new Node<_Tp>(0);
  auto pcur = tempNode;
  auto premax = tempNode;
  pcur->next = pq.head;
  premax->next = pq.head;
  
  while (pcur->next != pq.tail) {
    if (pcur->next->data > premax->next->data) {
      premax = pcur;
    }
    pcur = pcur->next;
  }

  auto ret = premax->next->data;
  
  --pq.n;
  auto temp = premax->next->next;
  delete premax->next;
  premax->next = temp;

  delete tempNode;

  return ret;
}

#endif /* ORDERED_LIST_PQ_H */
