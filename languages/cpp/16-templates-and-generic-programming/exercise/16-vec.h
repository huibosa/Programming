/* Rewrite the StrVec class (§ 13.5, p. 526) as a template named Vec. */

#ifndef VEC_H
#define VEC_H

#include <cstddef>
#include <initializer_list>
#include <memory>
#include <stdexcept>
#include <utility>
#include <algorithm>

template <typename _Tp> class Vec {
public:
  Vec() : front(nullptr), rear(nullptr), pivot(nullptr) {}
  Vec(const Vec &rhs);
  Vec(Vec &&rhs) noexcept;
  Vec(std::initializer_list<_Tp> init);
  Vec &operator=(const Vec &rhs);
  Vec &operator=(Vec &&rhs) noexcept;
  ~Vec();

public:
  void push_back(const _Tp &str);
  void push_back(_Tp &&t) noexcept;
  size_t size() const { return pivot - front; }
  size_t capacity() const { return rear - front; }
  void reserve(size_t n);
  void resize(size_t n) { resize(n, _Tp()); }
  void resize(size_t n, const _Tp &t);
  _Tp *begin() { return front; }
  _Tp *end() { return pivot; }
  const _Tp *begin() const { return front; }
  const _Tp *end() const { return pivot; }

private:
  void check_n_alloc();
  std::pair<_Tp *, _Tp *> alloc_n_copy(const _Tp *, const _Tp *);
  void free();
  void reallocate();
  void alloc_n_move(size_t n);

private:
  std::allocator<_Tp> alloc;
  _Tp *front;
  _Tp *pivot;
  _Tp *rear;
};

template <typename _Tp> Vec<_Tp>::Vec(std::initializer_list<_Tp> init) {
  auto data = alloc_n_copy(init.begin(), init.end());
  front = data.first;
  rear = pivot = data.second;
}

template <typename _Tp> Vec<_Tp>::Vec(const Vec &rhs) {
  auto data = alloc_n_copy(rhs.begin(), rhs.end());
  front = data.first;
  rear = pivot = data.second;
}

template <typename _Tp>
Vec<_Tp>::Vec(Vec &&rhs) noexcept
    : front(rhs.front), pivot(rhs.pivot), rear(rhs.rear) {
  rhs.front = rhs.pivot = rhs.rear = nullptr;
}

template <typename _Tp> Vec<_Tp> &Vec<_Tp>::operator=(const Vec &rhs) {
  auto data = alloc_n_copy(rhs.begin(), rhs.end());
  free();

  front = data.first;
  pivot = rear = data.second;

  return *this;
}

template <typename _Tp> Vec<_Tp> &Vec<_Tp>::operator=(Vec &&rhs) noexcept {
  if (this != &rhs) {
    free();
    front = rhs.front;
    pivot = rhs.pivot;
    rear = rhs.rear;

    rhs.front = rhs.pivot = rhs.rear = nullptr;

    return *this;
  }
}

template <typename _Tp> Vec<_Tp>::~Vec() { free(); }

template <typename _Tp> void Vec<_Tp>::push_back(const _Tp &t) {
  check_n_alloc();
  alloc.construct(pivot++, t);
}

template <typename _Tp> void Vec<_Tp>::push_back(_Tp &&t) noexcept {
  check_n_alloc();
  alloc.construct(pivot++, std::move(t));
}

template <typename _Tp> void Vec<_Tp>::reserve(size_t newCap) {
  if (capacity() <= newCap) {
    alloc_n_move(newCap);
  }
}

template <typename _Tp> void Vec<_Tp>::resize(size_t sz, const _Tp &t) {
  if (sz > size()) {
    reserve(sz);
    for ( /* empty */; pivot != rear; /* empty */) {
      alloc.construct(pivot++, t);
    }
  } else if (sz < size()) {
    for ( /* empty */; pivot != front + sz; /* empty */) {
      alloc.destroy(--pivot);
    }
  }
}

template <typename _Tp> void Vec<_Tp>::check_n_alloc() {
  if (size() == capacity()) {
    reallocate();
  }
}

template <typename _Tp>
std::pair<_Tp *, _Tp *> Vec<_Tp>::alloc_n_copy(const _Tp *b, const _Tp *e) {
  auto data = alloc.allocate(e - b);
  return {data, std::uninitialized_copy(b, e, data)};
}

template <typename _Tp> void Vec<_Tp>::free() {
  if (front) {
    for (/* empty */; pivot != front; /* empty */) {
      alloc.destroy(--pivot);
    }
    /* std::for_each(front, pivot, [this](_Tp & t) { alloc.destroy(&t); }); */
    alloc.deallocate(front, rear - front);

    front = nullptr;
    pivot = nullptr;
    rear = nullptr;
  }
}

template <typename _Tp> void Vec<_Tp>::reallocate() {
  auto newCap = size() ? size() * 2 : 1;
  alloc_n_move(newCap);
}

template <typename _Tp> void Vec<_Tp>::alloc_n_move(size_t newCap) {
  auto data = alloc.allocate(newCap);

  auto p = data;
  auto q = front;
  for (size_t i = 0; i < size(); ++i) {
    alloc.construct(p++, std::move(*q++));
  }

  free();

  front = data;
  pivot = p;
  rear = data + newCap;
}

#endif /* STRVEC_H */
