#include "32_StrBlobPtr_pointer.h"

StrBlobPtr& StrBlobPtr_pointer::operator*() const {
  return *pointer;
}

StrBlobPtr* StrBlobPtr_pointer::operator->() const {
  return pointer;
}
