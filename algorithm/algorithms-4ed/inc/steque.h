/* steque build with two stack */

#ifndef STEQUE_H_DFNZNFEM
#define STEQUE_H_DFNZNFEM

#include <iostream>
#include <stack>
#include <deque>
#include <stdexcept>

class Steque {
public:
  Steque() = default;
public:
  void push(const int item);
  void enqueue(const int item);
  int pop();
  bool empty() const { return size() == 0; }
  int size() const { return tail.size() + head.size(); }
private:
  void to_head();
private:
  std::stack<int> tail;
  std::stack<int> head;
};

inline void Steque::enqueue(const int item) {
  tail.push(item);
};

inline void Steque::push(const int item) {
  head.push(item);
};

inline int Steque::pop() {
  if (this->empty()) {
    throw std::out_of_range("empty steque!");
  }
  
  if (head.empty()) {
    to_head();
  }
  auto ret = head.top();
  head.pop();

  return ret;
}

inline void Steque::to_head() {
  while (!tail.empty()) {
    head.push(tail.top());
    tail.pop();
  }
}

#endif /* end of include guard: STEQUE_H_DFNZNFEM */
