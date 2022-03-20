#include <iostream>
#include <deque>
#include <memory>
#include <stdexcept>

class TwoStacks {
public:
  TwoStacks();
public:
  void pushStack1(int n);
  void pushStack2(int n);
  void popStack1();
  void popStack2();
  int peekStack1() const { return pq->front(); }
  int peekStack2() const { return pq->back(); }
  int stack1Size() const { return size1; }
  int stack2Size() const { return size2; }
  bool isStack1Empty() const { return size1 == 0; }
  bool isStack2Empty() const { return size2 == 0; }
private:
  std::unique_ptr<std::deque<int>> pq;
  int size1 = 0;
  int size2 = 0;
};

inline TwoStacks::TwoStacks() {
  pq.reset(new std::deque<int>());
};

inline void TwoStacks::pushStack1(int n) {
  pq->push_front(n);
  size1++;
};

inline void TwoStacks::pushStack2(int n) {
  pq->push_back(n);
  size2++;
};

inline void TwoStacks::popStack1() {
  if (isStack1Empty()) {
    throw std::runtime_error("Attempt to pop empty stack");
  }
  pq->pop_front();
  size1--;
};

inline void TwoStacks::popStack2() {
  if (isStack1Empty()) {
    throw std::runtime_error("Attempt to pop empty stack");
  }
  pq->pop_back();
  size2--;
};

int main() {
  std::unique_ptr<TwoStacks> ptwoStack(new TwoStacks());
  ptwoStack->pushStack1(1);
  ptwoStack->pushStack2(2);

  std::cout << ptwoStack->peekStack1() << std::endl;
  std::cout << ptwoStack->peekStack2() << std::endl;

  return 0;
}
