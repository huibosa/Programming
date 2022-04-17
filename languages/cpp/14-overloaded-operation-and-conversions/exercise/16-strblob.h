#ifndef STRBLOB_H
#define STRBLOB_H

#include <cstddef>
#include <list>
#include <utility>
#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <exception>
#include <stdexcept>

class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob {
friend class ConstStrBlobPtr;
friend class StrBlobPtr;
friend bool operator==(const StrBlob& lhs, const StrBlob& rhs);
friend bool operator!=(const StrBlob& lhs, const StrBlob& rhs);
using size_type = std::vector<std::string>::size_type;
public:
  StrBlob(): data(std::make_shared<std::vector<std::string>>()) {  }
  StrBlob(std::initializer_list<std::string> il)
        : data(std::make_shared<std::vector<std::string>>(il)) {  }
  
  StrBlob(const StrBlob& sb): data(std::make_shared<std::vector<std::string>>(*sb.data)) {  }
  StrBlob& operator=(const StrBlob &);

  StrBlob(StrBlob& sb): data(std::make_shared<std::vector<std::string>>(*sb.data)) {  }
  StrBlob& operator=(StrBlob &&) noexcept;
public:
  StrBlobPtr begin();
  StrBlobPtr end();
  ConstStrBlobPtr cbegin() const;
  ConstStrBlobPtr cend() const;
public:
  size_type size() const { return data->size(); }
  bool empty() const { return data->empty(); }
public:
  void push_back(const std::string& t) { data->push_back(t); }
  void push_back(std::string && s) { data->push_back(std::move(s)); }
  void pop_back();
  std::string& front();
  std::string& back();
  const std::string& front() const;
  const std::string& back() const;
public:
private:
  void check(size_type i, const std::string& msg) const;
  std::shared_ptr<std::vector<std::string>> data;
};

bool operator==(const StrBlob& lhs, const StrBlob& rhs);
bool operator!=(const StrBlob& lhs, const StrBlob& rhs);

inline void StrBlob::pop_back() {
  check(0, "pop_back on empty StrBlob");
  data->pop_back();
};

inline std::string& StrBlob::front() {
  check(0, "front on empty StrBlob");
  return data->front();
};

inline std::string& StrBlob::back() {
  check(0, "back on empty StrBlob");
  return data->back();
};

inline const std::string& StrBlob::front() const {
  check(0, "front on empty StrBlob");
  return data->front();
};

inline const std::string& StrBlob::back() const {
  check(0, "back on empty StrBlob");
  return data->back();
};

inline void StrBlob::check(size_type i, const std::string& msg) const {
  if (data->size() <= i) {
    throw std::out_of_range(msg);
  }
};


class StrBlobPtr {
friend bool operator==(const StrBlobPtr&, const StrBlobPtr&);
friend bool operator!=(const StrBlobPtr&, const StrBlobPtr&);
public:
  StrBlobPtr(): curr(0) {  }
  StrBlobPtr(StrBlob& s, size_t sz = 0): wptr(s.data), curr(sz) {  }
public:
  std::string& deref() const;
  StrBlobPtr& incr();
private:
  std::shared_ptr<std::vector<std::string>> check(size_t, const std::string&) const;
  std::weak_ptr<std::vector<std::string>> wptr;
  size_t curr;
};

bool operator==(const StrBlobPtr&, const StrBlobPtr&);
bool operator!=(const StrBlobPtr&, const StrBlobPtr&);

inline std::string& StrBlobPtr::deref() const {
  auto p = check(curr, "dereference past end");
  return (*p)[curr];
}

inline StrBlobPtr& StrBlobPtr::incr() {
  check(curr, "increment past end of StrBlobPtr");
  ++curr;
  return *this;
};

inline std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(size_t i, const std::string& msg) const {
  auto ret = wptr.lock();
  
  if (!ret) { throw std::runtime_error("unbound StrBlobPtr"); }
  if (i >= ret->size()) { throw std::out_of_range(msg); }

  return ret;
};

class ConstStrBlobPtr {
friend bool operator==(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
friend bool operator!=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
public:
  ConstStrBlobPtr(): curr(0) {  }
  ConstStrBlobPtr(const StrBlob& s, size_t sz = 0): wptr(s.data), curr(sz) {  }
public:
  const std::string& deref() const;
  ConstStrBlobPtr& incr();
private:
  std::shared_ptr<std::vector<std::string>> check(size_t, const std::string&) const;
  std::weak_ptr<std::vector<std::string>> wptr;
  size_t curr;
};

bool operator==(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
bool operator!=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);

inline const std::string& ConstStrBlobPtr::deref() const {
  auto p = check(curr, "dereference past end");

  return (*p)[curr];
};

inline ConstStrBlobPtr& ConstStrBlobPtr::incr() {
  check(curr, "increment past end of StrBlobPtr");
  ++curr;

  return *this;
};

inline std::shared_ptr<std::vector<std::string>>
ConstStrBlobPtr::check(size_t i, const std::string& msg) const {
  auto ret = wptr.lock();

  if (!ret) { throw std::runtime_error("unbound StrBlobPtr"); }
  if (i > ret->size()) { throw std::out_of_range(msg); }

  return ret;
};

#endif /* end of include guard: STRBLOB_H */
