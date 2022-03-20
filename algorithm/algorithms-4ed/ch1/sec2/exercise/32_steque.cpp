/* 1.3.32 Steque. A stack-ended queue or steque is a data type that supports push, pop, and */
/* enqueue. Articulate an API for this ADT. Develop a linked-list-based implementation. */
/* 1.3.33 Deque. A double-ended queue or deque (pronounced “deck”) is like a stack or */

#include <list>
#include <iostream>
#include <list>

class Steque {
public:
  Steque() = default;
public:
  void push(int item);
  void pop(int item);
private:
  std::list<int> lst;
};
