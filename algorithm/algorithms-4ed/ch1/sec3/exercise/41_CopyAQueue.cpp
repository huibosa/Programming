#include <iostream>
#include <queue>
#include <memory>

void printQueue(std::queue<int> q) {
  while (!q.empty()) {
    std::cout << q.front() << " ";
    q.pop();
  }
  std::cout << std::endl;
}

int main() {
  auto pq1 = std::make_shared<std::queue<int>>();
  auto pq2 = std::make_shared<std::queue<int>>();

  for (int i = 0; i < 10; ++i) {
    pq1->push(i);
  }
  auto size = pq1->size();

  for (auto size = pq1->size(); size != 0; --size) {
    auto temp = pq1->front();
    pq1->pop();
    pq1->push(temp);
    pq2->push(temp);
  }

  printQueue(*pq1);
  printQueue(*pq2);

  return 0;
}
