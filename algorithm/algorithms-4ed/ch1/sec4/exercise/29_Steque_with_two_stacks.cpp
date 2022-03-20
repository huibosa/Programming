/* 1.4.29 Steque with two stacks. Implement a steque with two stacks so that each steque */
/* operation (see Exercise 1.3.32) takes a constant amortized number of stack operations. */

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
  void pop();
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

inline void Steque::pop() {
  if (this->empty()) {
    throw std::out_of_range("empty steque!");
  }
  
  if (head.empty()) {
    to_head();
  }
  head.pop();
}

inline void Steque::to_head() {
  while (!tail.empty()) {
    head.push(tail.top());
    tail.pop();
  }
}

int main() {
  auto st = new Steque();
  st->push(1);
  st->push(2);
  std::cout << st->size() << "\n";
  st->pop();
  std::cout << st->size() << "\n";
  st->enqueue(3);
  std::cout << st->size() << "\n";

  return 0;
}
