#include <iostream>
#include <queue>
#include <algorithm>
#include <deque>
#include "14_Mergeing_sorted_queues.h"

int main() {
  std::deque<int> dq1(1, 1);
  std::deque<int> dq2(1, 2);
  std::deque<int> dq3(1, 3);
  std::deque<int> dq4(1, 4);
  std::deque<int> dq5(1, 5);
  std::deque<int> dq6(1, 6);
  std::deque<int> dq7(1, 7);
  std::deque<int> dq8(1, 8);
  
  std::queue<int> q1(dq1);
  std::queue<int> q2(dq2);
  std::queue<int> q3(dq3);
  std::queue<int> q4(dq4);
  std::queue<int> q5(dq5);
  std::queue<int> q6(dq6);
  std::queue<int> q7(dq7);
  std::queue<int> q8(dq8);

  std::queue<std::queue<int>> super;
  super.push(q7);
  super.push(q3);
  super.push(q3);
  super.push(q8);
  super.push(q2);
  super.push(q4);
  super.push(q5);
  super.push(q8);

  MergeQueue<int> mergeQ;
  while (super.size() != 1) {
    auto temp = super.front();
    super.pop();
    auto newQ = mergeQ.merge(temp, super.front());
    super.pop();
    super.push(newQ);
  }

  auto ret = super.front();

  while (!ret.empty()) {
    std::cout << ret.front() << " ";
    ret.pop();
  }
  std::cout << "\n";

  return 0;
}
