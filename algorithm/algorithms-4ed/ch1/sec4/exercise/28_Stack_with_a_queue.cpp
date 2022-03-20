#include <iostream>
#include <queue>

class Stack {
public:
  Stack() = default;
public:
  void push(int item);
  void pop();
  int top();
  int size() const { return q.size(); }
  bool empty() const { return q.empty(); }
private:
  std::queue<int> q;
};

inline void Stack::push(int item) {
  q.push(item);
};

inline void Stack::pop() {
  if (empty()) {
    throw std::out_of_range("empty");
  }
  for (int i = 0; i < size() - 1; ++i) {
    q.push(q.front());
    q.pop();
  }
}
