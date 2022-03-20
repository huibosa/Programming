#include <iostream>
#include <stack>

class Deque {
public:
  Deque() = default;
public:
  void push_front(int item);
  void push_back(int item);
  void pop_front();
  void pop_back();
  int size() const { return stack1.size() + stack2.size() + stack3.size();}
  bool empty() const { return size() == 0; }
private:
  std::stack<int> stack1;
  std::stack<int> stack2;
  std::stack<int> stack3;
};

inline void Deque::push_front(int item) {
};

inline void Deque::push_back(int item) {
};

inline void Deque::pop_back() {
};

inline void Deque::pop_front() {
};
