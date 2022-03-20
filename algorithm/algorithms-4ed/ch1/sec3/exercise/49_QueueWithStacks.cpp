
#include <iostream>
#include <memory>
#include <stack>

class Queue {
public:
  Queue();
public:
  void enqueue(int n);
  void dequeue();
  int front() const;
  int back() const;
  int size() const { return sz; }
  bool empty() const { return sz == 0; }
private:
  std::stack<int> head;
  std::stack<int> tail;

  std::stack<int> reverseHead;
  std::stack<int> reverseTail;

  int sz = 0;
};
