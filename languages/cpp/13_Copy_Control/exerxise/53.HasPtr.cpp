/* https://stackoverflow.com/questions/21010371/why-is-it-not-efficient-to-use-a-single-assignment-operator-handling-both-copy-a */

#include "53_HasPtr.h"
#include <string>
#include <type_traits>
#include <vector>


inline void swap(HasPtr& lhs, HasPtr& rhs) {
  using std::swap;
  swap(lhs.ps, rhs.ps);
  swap(lhs.i, rhs.i);
}

HasPtr::HasPtr(const std::string &s) : ps(new std::string(s)), i(0) {}

HasPtr::HasPtr(const HasPtr &rhs) : ps(new std::string(*rhs.ps)), i(rhs.i) {}

HasPtr::HasPtr(HasPtr&& rhs) noexcept : ps(rhs.ps), i(rhs.i) {
  rhs.ps = nullptr;
}

HasPtr& HasPtr::operator=(HasPtr rhs) {
  std::swap(*this, rhs);
  return *this;
}

HasPtr::~HasPtr() {
  delete ps;
}
