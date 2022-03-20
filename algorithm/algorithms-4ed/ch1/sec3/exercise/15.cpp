#include <cstddef>
#include <iostream>
#include <queue>
#include <memory>
#include <string>
#include <list>
#include <sstream>

using Queue = std::queue<std::string, std::list<std::string>>;

void printItems(std::shared_ptr<std::list<std::string>> pq, int k) {
  auto cnt = 0;
  for (const auto& str : *pq) {
    ++cnt;
    if (cnt >= k) {
      std::cout << str << std::endl;
    }
  }
}

void initQueue(std::shared_ptr<std::list<std::string>> pq, const std::string& s) {
#if 0
  std::istringstream str(s);
  std::string temp;
  while (str >> temp) {
    pq->push_back(temp);
  }
#endif

  // "a b c d"
  std::string delimiter = " ";

  std::size_t pos = 0;
  while ((pos = s.find(delimiter, pos)) != std::string::npos) {
    pq->push_back(s.substr(pos - 1, 1));
    ++pos;
  }
}

int main(int argc, char** argv) {
  auto k = std::stoi(argv[1]);
  auto pq = std::make_shared<std::list<std::string>>();
  
  initQueue(pq, argv[2]);

  printItems(pq, k);

  return 0;
}
