#include <cstddef>
#include <queue>
#include <iostream>
#include <memory>
#include <string>

std::string *readDates() {
  auto q = std::make_shared<std::queue<std::string>>();

  for (std::string temp; std::cin >> temp; ) {
    q->push(temp);
  }

  std::size_t N = q->size();
  auto a = new std::string[N]();
  for (std::size_t i = 0; i < N; ++i) {
    a[i] = q->front();
    q->pop();
  }

  return a;
}
