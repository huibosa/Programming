#include <cstdlib>
#include <iostream>
#include <vector>
#include <functional>
#include <iomanip>
#include "inc/MinPQ.h"

template <typename _Tp> bool certification(const _Tp* pq, int n) {
  std::less<_Tp> less;
  
  for (int i = 1; i <= n/2; ++i) {
    if (!less(pq[i], pq[2*i])) { // check left child
      return false;
    }
    if (i*2+1 < n && !less(pq[i], pq[i*2+1])) { // check right child
      return false;
    }
  }
  
  return true;
}

template <typename _Tp, unsigned _Nm> unsigned getArraySize(const _Tp (&) [_Nm]) {
  return _Nm;
}


int main() {
  auto minOrientedHeap = new int[11]();
  int p[10] = {0, 0, 1, 2, 3, 4, 5, 6, 7, 8};
  minOrientedHeap = p;
  
  int q[10] = {0, 0, 1, 2, -1, -5, 99, 6, 7, 8};
  auto notMinOrientedHeap = new int[11]();
  notMinOrientedHeap = q;
  
  std::cout << certification(minOrientedHeap, 10) << "\n";
  std::cout << certification(notMinOrientedHeap, 10) << "\n";
  
  return 0;
}
