#include <iostream>
#include "inc/steque.h"
#include <stack>
#include <stdexcept>

using Stack = std::stack<int>;

class Deque {
public:
  Deque() = default;
public:
  void push_front(int item);
  void push_back(int item);
  void pop_front();
  void pop_back();
  int size() const { return stack.size() + steque.size();}
  bool empty() const { return size() == 0; }
private:
  void to_stack();
  void move_half_item_from_steque_to_stack();
private:
  Stack stack;
  Steque steque;
};

inline void Deque::push_front(int item) {
  stack.push(item);
};

// amortized O(1)
inline void Deque::push_back(int item) {
  steque.push(item);
};

inline void Deque::pop_back() {
  if (this->empty()) {
    throw std::runtime_error("Deque underflow");
  }
  if (stack.empty()) {
    to_stack();
  }
  stack.pop();
};

inline void Deque::pop_front() {
  if (this->empty()) {
    throw std::runtime_error("Deque underflow");
  }
  
  if (stack.empty()) {
    move_half_item_from_steque_to_stack();
  }

  stack.pop();
};

inline void Deque::to_stack() {
  while (!steque.empty()) {
    stack.push(steque.pop());
  }
};

inline void Deque::move_half_item_from_steque_to_stack() {
  int halfStequeSize = steque.size() / 2;
  int remainingStequeSize = steque.size() - halfStequeSize;

  for (int i = 0; i < halfStequeSize; ++i) {
    steque.enqueue(steque.pop());
  }
};

int main() {
  auto deq = new Deque();

  return 0;
}
