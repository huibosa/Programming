#ifndef BLOBPTR_H
#define BLOBPTR_H

#include "12_Blob.h"
#include <cstddef>
#include <iterator>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

template <typename> class BlobPtr;

template <typename _Tp>
bool operator==(const BlobPtr<_Tp> &lhs, const BlobPtr<_Tp> &rhs);

template <typename _Tp>
bool operator<(const BlobPtr<_Tp> &lhs, const BlobPtr<_Tp> &rhs);

template <typename _Tp> class BlobPtr {
  friend bool operator==<_Tp>(const BlobPtr<_Tp> &lhs, const BlobPtr<_Tp> &rhs);
  friend bool operator< <_Tp>(const BlobPtr<_Tp> &lhs, const BlobPtr<_Tp> &rhs);

public:
  BlobPtr() : curr(0) {}
  BlobPtr(Blob<_Tp> &a, size_t sz = 0) : wptr(a.data), curr(sz) {}

private:
  std::shared_ptr<std::vector<_Tp>> check(size_t i,
                                          const std::string &msg) const;
  std::weak_ptr<std::vector<_Tp>> wptr;
  size_t curr;
};

template <typename _Tp>
bool operator==(const BlobPtr<_Tp> &lhs, const BlobPtr<_Tp> &rhs) {
  if (rhs.wptr.lock() != rhs.wptr.lock()) {
    throw std::runtime_error("ptrs to different Blobs");
  }
  return lhs.curr == rhs.curr;
}

template <typename _Tp>
std::shared_ptr<std::vector<_Tp>>
BlobPtr<_Tp>::check(size_t i, const std::string &msg) const {
  auto ret = wptr.lock();
  if (!ret) {
    throw std::runtime_error("invalid Blob");
  }
  if (i >= ret->size()) {
    throw std::out_of_range(msg);
  }
  return ret;
}

#endif /* BLOBPTR_H */
