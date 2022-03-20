#include <bits/c++config.h>
#include <cstddef>
#include <iostream>
#include <memory>
#include <string>
#include <queue>

const int CAPACITY = 20;

class StrQueue {
public:
  StrQueue();
  virtual ~StrQueue();
public:
  void push(const std::string& s);
  void pop();
  std::size_t size() { return curr; }
  bool empty() { return curr == 0; }
  std::string& front() { return pq[0]; }
  std::string& back() { return pq[curr-1]; }
  const std::string& front() const  { return pq[0]; }
  const std::string& back() const { return pq[curr-1]; }
private:
  void resize(std::size_t size);
private:
  std::string* pq;
  std::size_t curr = 0;   /* curr point to the first empty slot */
  std::size_t cap;
};

inline StrQueue::StrQueue() {
  cap = CAPACITY;
  pq = new std::string[cap]();
  curr = 0;
};

inline StrQueue::~StrQueue() {
  delete [] pq;
}

inline void StrQueue::push(const std::string &s) {
  if (size() == cap) {
    resize(2 * cap);
  }
  pq[curr++] = s;
};

inline void StrQueue::pop() {
  if (size() > 0 && size() == cap / 4) {
    resize(cap / 2);
  }
  --curr;
};

inline void StrQueue::resize(std::size_t size) {
  auto temp = new std::string[size]();
  cap = size;

  for (std::size_t i = 0; i < curr; ++i) {
    temp[i] = pq[i];
  }

  delete [] pq;
  pq = temp;
};

int main() {
  StrQueue q;
  for (std::size_t i = 0; i < 100; ++i) {
    q.push(std::to_string(i));
  }

  std::cout << q.front() << std::endl;
  std::cout << q.back() << std::endl;
  q.pop();
  std::cout << q.front() << std::endl;
  std::cout << q.back() << std::endl;

  return 0;
}
