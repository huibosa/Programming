#include <cstddef>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <cstdio>


class RingBuffer {
public:
  using Item = std::size_t;
  RingBuffer(std::size_t s): sz(s), pq(new Item[s]()) {  }
  ~RingBuffer() { delete [] pq; }
public:
  void write(Item item);
  void read(Item* pi);
  std::size_t size() const { return sz; }
  bool isFull() const { return bufferIsFull; }
  bool isEmpty() const { return head == tail && !bufferIsFull; }
private:
  Item* pq = nullptr;
  std::size_t sz = 0;
  std::size_t head = 0;
  std::size_t tail = 0;
  bool bufferIsFull = false;
};

inline void RingBuffer::write(Item item) {
  if (this->isFull()) {
    printf("buffer overflow\n");
  } else {
    pq[head] = item;
    printf("Wirte to buffer: %lu", pq[head]);
    printf("\tHead = %lu\tTail = %lu\tbufferIsFull = %d\n",
        head, tail, bufferIsFull);
    head = (head + 1) % size();
    if (head == tail) { bufferIsFull = true; }
  }
};

inline void RingBuffer::read(Item* pi) {
  if (this->isEmpty()) {
    printf("buffer underflow");
  } else {
    *pi = pq[tail];
    printf("Read from buffer: %lu\n", pq[tail]);
    tail = (tail + 1) % size();
    bufferIsFull = false;
  }
};

int main() {
  RingBuffer rb(10);
  
  rb.write(2);
  rb.write(3);
  rb.write(4);
  rb.write(5);
  rb.write(6);

  RingBuffer::Item dummy;
  rb.read(&dummy);
  rb.read(&dummy);

  return 0;
}
