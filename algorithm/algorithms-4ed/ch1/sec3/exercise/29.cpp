#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <memory>

class Node {
public:
  Node() = default;
  Node(int i): item(i) {  }
public:
  Node* next = nullptr;
  int item = 0;
};

class Queue {
public:
  Queue() = default;
public:
  void push(int item);
  void pop();
  int& front() { return tail->item; }
  int& back() { return tail->next->item; }
  bool empty() { return tail == nullptr; }
  std::size_t size() const;
private:
  Node* tail = nullptr;
};

inline void Queue::push(int item) {
  auto pn = new Node(item);

  if (this->empty()) {
    tail = pn;
    tail->next = tail;
  }
  else {
    pn->next = tail->next;
    tail->next = pn;
    tail = pn;
  }
};

inline void Queue::pop() {
  if (this->empty()) {
    fprintf(stderr, "Attempt to pop empty queue\n");
    std::exit(1);
  }

  auto front = tail->next;
  tail->next = tail->next->next;
  delete front;
};

inline std::size_t Queue::size() const {
  std::size_t ret = 0;

  auto cur = tail->next;
  while (cur != tail) {
    cur = cur->next;
    ++ret;
  }
  ++ret;

  return ret;
};

int main() {
  Queue q;
  for (int i = 0; i < 20; ++i) {
    q.push(i);
  }

  q.pop();

  std::cout << q.front() << std::endl;
  std::cout << q.back() << std::endl;
  std::cout << q.size() << std::endl;
  return 0;
}
