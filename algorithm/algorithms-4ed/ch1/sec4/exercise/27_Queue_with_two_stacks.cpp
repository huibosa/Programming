#include <iostream>
#include <memory>
#include <stack>
#include <stdexcept>

class Queue {
public:
  Queue() = default;
public:
  void dequeue();
  void enqueue(const int item);
  int front() { return head.top(); }
  int back() { return tail.top(); }
  int size() const { return tail.size() + head.size(); }
  bool empty() const { return size() == 0; }  // O(1)
private:
  void to_head();
private:
  std::stack<int> tail;
  std::stack<int> head;
};

// amortiezd O(1)
inline void Queue::dequeue() {
  if (head.empty()) {
    to_head();
  }
  head.pop();
};

inline void Queue::enqueue(const int item) {
  tail.push(item);
}

inline void Queue::to_head() {
  while (!tail.empty()) {
    head.push(tail.top());
    tail.pop();
  }
}

int main() {
  auto q = new Queue();

  for (int i = 0; i < 5; ++i) {
    q->enqueue(i);
  }

  std::cout << q->front() << "\n";
  std::cout << q->back() << "\n";

  q->dequeue();
  std::cout << q->front() << "\n";
  std::cout << q->back() << "\n";

  return 0;
}
