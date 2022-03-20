#include <cstddef>
#include <iostream>
#include <memory>
#include <stdexcept>

class GeneralizedQueue {
public:
  using Item = int;
  GeneralizedQueue(std::size_t cap);
  virtual ~GeneralizedQueue();
public:
  void insert(const Item& s);
  Item deleteKth(std::size_t k);
  bool isEmpty() { return sz == 0; }
  bool isFull() { return sz == cap; }
  std::size_t size() { return sz; }
private:
  void resize(std::size_t size);
  void fillSlot(std::size_t k);
private:
  Item* pq;
  std::size_t sz = 0;   /* curr point to the first empty slot */
  std::size_t cap;
};

inline GeneralizedQueue::GeneralizedQueue(std::size_t c) {
  cap = c;
  pq = new Item[c]();
  sz = 0;
};

inline GeneralizedQueue::~GeneralizedQueue() {
  delete [] pq;
}

inline void GeneralizedQueue::insert(const Item &s) {
  if (this->isFull()) {
    resize(2 * cap);
  }
  pq[sz++] = s;
};

inline GeneralizedQueue::Item GeneralizedQueue::deleteKth(std::size_t k) {
  if (isEmpty()) {
    throw std::runtime_error("Queue underflow");
  }
  if (k < 0 || this->size() < k) {
    throw std::runtime_error("Invalid index");
  }

  auto ret = pq[sz-k];
  fillSlot(sz - k);

  sz--;

  if (size() < cap / 4) {
    resize(cap / 2);
  }

  return ret;
};

inline void GeneralizedQueue::resize(std::size_t size) {
  auto temp = new Item[size]();
  cap = size;

  for (std::size_t i = 0; i < sz; ++i) {
    temp[i] = pq[i];
  }

  delete [] pq;
  pq = temp;
};

inline void GeneralizedQueue::fillSlot(std::size_t firstIndex) {
  for (std::size_t i = firstIndex; i < sz - 1; i++) {
    pq[i] = pq[i+1];
  }
};

int main() {
  GeneralizedQueue q(10);
  for (std::size_t i = 0; i < 10; ++i) {
    q.insert(i);
  }

  std::cout << q.deleteKth(2) << std::endl;

  return 0;
}
