#include <queue>
#include <iostream>
#include <memory>

int* readInts() {
  auto q = std::make_shared<std::queue<int>>();
  int temp;

  while (std::cin >> temp) {
    q->push(temp);
  }

  int N = q->size();
  auto a = new int[N]();
  for (int i = 0; i < N; ++i) {
    a[i] = q->front();
    q->pop();
  }

  return a;
}
