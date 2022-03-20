#include <stack>
#include <queue>
#include <deque>
#include <iostream>
#include <memory>

int main() {
  auto pq = std::make_shared<std::queue<int>>();
  auto ps = std::make_shared<std::stack<int>>();

  for (int i = 0; i < 10; ++i) {
    pq->push(i);
  }

  while (!pq->empty()) {
    ps->push(pq->front());
    pq->pop();
  }

  while (!ps->empty()) {
    pq->push(ps->top());
    ps->pop();
  }

  std::cout << "Items in queue now: " << std::endl;
  while (!pq->empty()) {
    std::cout << pq->front();
    pq->pop();
  }
  std::cout << std::endl;

  return 0;
}
