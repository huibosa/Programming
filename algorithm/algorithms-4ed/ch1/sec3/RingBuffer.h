#pragma once

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
    throw std::runtime_error("buffer overflow\n");
  }

  pq[head] = item;
  head = (head + 1) % size();
  if (head == tail) { bufferIsFull = true; }
};

inline void RingBuffer::read(Item* pi) {
  if (this->isEmpty()) {
    throw std::runtime_error("buffer overflow\n");
  }

  *pi = pq[tail];
  tail = (tail + 1) % size();
  bufferIsFull = false;
};
