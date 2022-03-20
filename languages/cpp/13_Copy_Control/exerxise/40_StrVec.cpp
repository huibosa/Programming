#include "40_StrVec.h"
#include <cstddef>
#include <initializer_list>
#include <string>
#include <utility>

StrVec::StrVec(const StrVec &rhs) {
  auto res = alloc_n_copy(rhs.begin(), rhs.end());

  front = res.first;
  rear = pivot = res.second;
}

StrVec::StrVec(std::initializer_list<std::string> ls) {
  auto data = alloc_n_copy(ls.begin(), ls.end());
  front = data.first;
  rear = pivot = data.second;
}

StrVec &StrVec::operator=(const StrVec &rhs) {
  auto res = alloc_n_copy(rhs.begin(), rhs.end());

  free(); // free here to prevent self copy

  front = res.first;
  rear = pivot = res.second;

  return *this;
}

StrVec::~StrVec() { free(); }

void StrVec::push_back(const std::string &str) {
  check_n_alloc();
  alloc.construct(pivot++, str);
}

void StrVec::check_n_alloc() {
  if (size() == capacity()) {
    reallocate();
  }
}

std::pair<std::string *, std::string *>
StrVec::alloc_n_copy(const std::string *b, const std::string *e) {
  auto data = alloc.allocate(e - b);
  return {data, std::uninitialized_copy(b, e, data)};
}

void StrVec::free() {
  if (front) {
    for (/* empty */; pivot != front; /* empty */) {
      alloc.destroy(--pivot);
    }
    alloc.deallocate(front, rear - front);
  }
}

void StrVec::alloc_n_move(size_t newCap) {
  auto newData = alloc.allocate(newCap);

  auto p = newData;
  auto q = front;
  for (size_t i = 0; i < size(); ++i) {
    alloc.construct(p++, std::move(*q++));
  }

  free();

  front = newData;
  pivot = p;
  rear = front + newCap;
}

void StrVec::reallocate() {
  auto newCap = size() ? size() * 2 : 1;
  alloc_n_move(newCap);
}

void StrVec::reserve(size_t newCap) {
  if (capacity() < newCap) {
    alloc_n_move(newCap);
  }
}

// TODO: huibosa
void StrVec::resize(size_t sz, const std::string &t) {
  if (size() < sz) {
    /* if (sz > capacity()) reserve(sz * 2); */
    reserve(sz);
    
    for (/* empty */; pivot != front + sz; /* empty */) {
      alloc.construct(pivot++, t);
    }
  } else if (size() > sz) {
    for (/* empty */; pivot != front + sz; /* empty */) {
      alloc.destroy(--pivot);
    }
  }
}
