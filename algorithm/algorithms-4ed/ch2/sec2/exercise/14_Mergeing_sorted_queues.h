#pragma once

#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

template <typename _Tp> class MergeQueue {
public: 
  std::queue<_Tp> merge(std::queue<_Tp> q1, std::queue<_Tp> q2);
};


template <typename _Tp>
std::queue<_Tp> MergeQueue<_Tp>::merge(std::queue<_Tp> q1, std::queue<_Tp> q2) {
  std::queue<_Tp> ret;

  while (!q1.empty() && !q2.empty()) {
    if (q1.front() < q2.front()) {
      ret.push(q1.front());
      q1.pop();
    } else {
      ret.push(q2.front());
      q2.pop();
    }
  }

  while (!q1.empty()) {
    ret.push(q1.front());
    q1.pop();
  }
  while (!q2.empty()) {
    ret.push(q2.front());
    q2.pop();
  }

  return ret;
}
