#ifndef BLOB_H
#define BLOB_H

#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

template<typename _Tp> class BlobPtr;

template <typename _Tp> class Blob {
  friend class BlobPtr<_Tp>;
public:
  typedef typename std::vector<_Tp>::size_type size_type;
  Blob() : data(std::make_shared<std::vector<_Tp>>()) {}
  Blob(std::initializer_list<_Tp> il)
      : data(std::make_shared<std::vector<_Tp>>()) {}

  size_type size() const { return data->size(); }
  bool empty() const { return data->empty(); }
  void push_back(const _Tp &t) { data->push_back(t); }
  void push_back(_Tp &&t) { data->push_back(std::move(t)); }
  void pop_back();
  _Tp &back();
  _Tp &operator[](size_type i);
  const _Tp &back() const;
  const _Tp &operator[](size_type i) const;

private:
  void check(size_type i, const std::string &msg) const;
  std::shared_ptr<std::vector<_Tp>> data;
};

template <typename _Tp>
void Blob<_Tp>::check(size_type i, const std::string &msg) const {
  if (i >= data->size()) {
    throw std::out_of_range(msg);
  }
}

template <typename _Tp> void Blob<_Tp>::pop_back() {
  check(0, "pop on empty Blob");
  data->pop_back();
}

template <typename _Tp> _Tp &Blob<_Tp>::back() {
  check(0, "empty Blob");
  return data->back();
}

template <typename _Tp> const _Tp &Blob<_Tp>::back() const {
  check(0, "empty Blob");
  return data->back();
}

template <typename _Tp> _Tp &Blob<_Tp>::operator[](size_type i) {
  check(i, "subscript out of range");
  return data->at(i);
}

template <typename _Tp> const _Tp &Blob<_Tp>::operator[](size_type i) const {
  check(i, "subscript out of range");
  return data->at(i);
}

#endif /* BLOB_H */
