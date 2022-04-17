/* Exercise 14.30: Add dereference and arrow operators to your StrBlobPtr */
/* class and to the ConstStrBlobPtr class that you defined in exercise 12.22 */
/* from § 12.1.6 (p. 476). Note that the operators in constStrBlobPtr must */
/* return const references because the data member in constStrBlobPtr */
/* points to a const vector. */

#ifndef STRBLOB_H
#define STRBLOB_H

#include <cstddef>
#include <exception>
#include <initializer_list>
#include <list>
#include <memory>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob {
  friend class ConstStrBlobPtr;
  friend class StrBlobPtr;
  friend bool operator==(const StrBlob &lhs, const StrBlob &rhs);
  friend bool operator!=(const StrBlob &lhs, const StrBlob &rhs);
  friend bool operator<(const StrBlob &lhs, const StrBlob &rhs);
  friend bool operator>(const StrBlob &lhs, const StrBlob &rhs);
  using size_type = std::vector<std::string>::size_type;

public:
  StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}
  StrBlob(std::initializer_list<std::string> il)
      : data(std::make_shared<std::vector<std::string>>(il)) {}

  StrBlob(const StrBlob &sb)
      : data(std::make_shared<std::vector<std::string>>(*sb.data)) {}
  StrBlob &operator=(const StrBlob &);

  StrBlob(StrBlob &sb)
      : data(std::make_shared<std::vector<std::string>>(*sb.data)) {}
  StrBlob &operator=(StrBlob &&) noexcept;

public:
  StrBlobPtr begin();
  StrBlobPtr end();
  ConstStrBlobPtr cbegin() const;
  ConstStrBlobPtr cend() const;
  std::string &operator[](size_type n);
  const std::string &operator[](size_type n) const;

public:
  size_type size() const { return data->size(); }
  bool empty() const { return data->empty(); }

public:
  void push_back(const std::string &t) { data->push_back(t); }
  void push_back(std::string &&s) { data->push_back(std::move(s)); }
  void pop_back();
  std::string &front();
  std::string &back();
  const std::string &front() const;
  const std::string &back() const;

public:
private:
  void check(size_type i, const std::string &msg) const;
  std::shared_ptr<std::vector<std::string>> data;
};

bool operator==(const StrBlob &lhs, const StrBlob &rhs);
bool operator!=(const StrBlob &lhs, const StrBlob &rhs);
bool operator<(const StrBlob &lhs, const StrBlob &rhs);
bool operator>(const StrBlob &lhs, const StrBlob &rhs);

inline void StrBlob::pop_back() {
  check(0, "pop_back on empty StrBlob");
  data->pop_back();
};

inline std::string &StrBlob::front() {
  check(0, "front on empty StrBlob");
  return data->front();
};

inline std::string &StrBlob::back() {
  check(0, "back on empty StrBlob");
  return data->back();
};

inline const std::string &StrBlob::front() const {
  check(0, "front on empty StrBlob");
  return data->front();
};

inline const std::string &StrBlob::back() const {
  check(0, "back on empty StrBlob");
  return data->back();
};

inline void StrBlob::check(size_type i, const std::string &msg) const {
  if (data->size() <= i) {
    throw std::out_of_range(msg);
  }
};

inline std::string &StrBlob::operator[](size_type n) {
  check(n, "subscript past Strblob end");

  return data->at(n);
}

inline const std::string &StrBlob::operator[](size_type n) const {
  check(n, "subscript past Strblob end");

  return data->at(n);
}

class StrBlobPtr {
  friend bool operator==(const StrBlobPtr &, const StrBlobPtr &);
  friend bool operator!=(const StrBlobPtr &, const StrBlobPtr &);
  friend bool operator<(const StrBlobPtr &, const StrBlobPtr &);
  friend bool operator>(const StrBlobPtr &, const StrBlobPtr &);

public:
  StrBlobPtr() : curr(0) {}
  StrBlobPtr(StrBlob &s, size_t sz = 0) : wptr(s.data), curr(sz) {}

public:
  std::string &deref() const;
  StrBlobPtr &incr();
  std::string &operator[](StrBlob::size_type n);
  const std::string &operator[](StrBlob::size_type n) const;
  StrBlobPtr &operator++();
  StrBlobPtr &operator--();
  StrBlobPtr operator++(int);
  StrBlobPtr operator--(int);
  StrBlobPtr &operator+=(size_t n);
  StrBlobPtr &operator-=(size_t n);
  StrBlobPtr operator+(size_t n) const;
  StrBlobPtr operator-(size_t n) const;
  std::string &operator*() const;
  std::string *operator->() const;

private:
  std::shared_ptr<std::vector<std::string>> check(size_t,
                                                  const std::string &) const;
  std::weak_ptr<std::vector<std::string>> wptr;
  size_t curr;
};

bool operator==(const StrBlobPtr &, const StrBlobPtr &);
bool operator!=(const StrBlobPtr &, const StrBlobPtr &);
bool operator<(const StrBlobPtr &, const StrBlobPtr &);
bool operator>(const StrBlobPtr &, const StrBlobPtr &);

inline std::string &StrBlobPtr::deref() const {
  auto p = check(curr, "dereference past end");
  return (*p)[curr];
}

inline StrBlobPtr &StrBlobPtr::incr() {
  check(curr, "increment past end of StrBlobPtr");
  ++curr;
  return *this;
};

inline std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(size_t i, const std::string &msg) const {
  auto ret = wptr.lock();

  if (!ret) {
    throw std::runtime_error("unbound StrBlobPtr");
  }
  if (i >= ret->size()) {
    throw std::out_of_range(msg);
  }

  return ret;
};

inline std::string &StrBlobPtr::operator[](StrBlob::size_type n) {
  auto p = check(n, "dereference out of range");
  return p->at(n);
}

inline const std::string &StrBlobPtr::operator[](StrBlob::size_type n) const {
  auto p = check(n, "dereference out of range");
  return p->at(n);
}

inline StrBlobPtr &StrBlobPtr::operator++() {
  check(curr, "increment past end of StrBlobPtr");
  ++curr;

  return *this;
}

inline StrBlobPtr StrBlobPtr::operator++(int) {
  auto ret = *this;
  ++(*this);
  return ret;
}

inline StrBlobPtr &StrBlobPtr::operator--() {
  check(--curr, "decrement past begin of StrBlobPtr");
  return *this;
}

inline StrBlobPtr StrBlobPtr::operator--(int) {
  auto ret = *this;
  --(*this);
  return ret;
}

inline StrBlobPtr &StrBlobPtr::operator+=(size_t n) {
  curr += n;
  check(curr, "increase n past end of StrBlobPtr");

  return *this;
}

inline StrBlobPtr &StrBlobPtr::operator-=(size_t n) {
  curr -= n;
  check(curr, "decrease n past end of StrBlobPtr");

  return *this;
}

inline StrBlobPtr StrBlobPtr::operator+(size_t n) const {
  auto ret = *this;
  ret += n;

  return ret;
}

inline StrBlobPtr StrBlobPtr::operator-(size_t n) const {
  auto ret = *this;
  ret -= n;

  return ret;
}

inline std::string &StrBlobPtr::operator*() const {
  auto p = check(curr, "dereference out of range");
  return (*p)[curr];
}

inline std::string *StrBlobPtr::operator->() const {
  return &this->operator*();
}

class ConstStrBlobPtr {
  friend bool operator==(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
  friend bool operator!=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
  friend bool operator<(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
  friend bool operator>(const ConstStrBlobPtr &, const ConstStrBlobPtr &);

public:
  ConstStrBlobPtr() : curr(0) {}
  ConstStrBlobPtr(const StrBlob &s, size_t sz = 0) : wptr(s.data), curr(sz) {}

public:
  const std::string &deref() const;
  ConstStrBlobPtr &incr();
  const std::string &operator[](StrBlob::size_type n) const;
  const std::string &operator*() const;
  const std::string *operator->() const;

private:
  std::shared_ptr<std::vector<std::string>> check(size_t,
                                                  const std::string &) const;
  std::weak_ptr<std::vector<std::string>> wptr;
  size_t curr;
};

bool operator==(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
bool operator!=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
bool operator<(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
bool operator>(const ConstStrBlobPtr &, const ConstStrBlobPtr &);

inline const std::string &ConstStrBlobPtr::deref() const {
  auto p = check(curr, "dereference past end");
  return (*p)[curr];
};

inline ConstStrBlobPtr &ConstStrBlobPtr::incr() {
  check(curr, "increment past end of StrBlobPtr");
  ++curr;

  return *this;
};

inline std::shared_ptr<std::vector<std::string>>
ConstStrBlobPtr::check(size_t i, const std::string &msg) const {
  auto ret = wptr.lock();

  if (!ret) {
    throw std::runtime_error("unbound StrBlobPtr");
  }
  if (i > ret->size()) {
    throw std::out_of_range(msg);
  }

  return ret;
};

inline const std::string &
ConstStrBlobPtr::operator[](StrBlob::size_type n) const {
  auto p = check(n, "subscript past StrBlobPtr end");
  return (*p)[n];
}

const std::string &ConstStrBlobPtr::operator*() const {
  auto p = check(curr, "dereference out of range");
  return (*p)[curr];
};

const std::string *ConstStrBlobPtr::operator->() const {
  return &this->operator*();
};

#endif
