/* Give your class a < operator and define a vector of */
/* HasPtrs. Give that vector some elements and then sort the vector. */
/* Note when swap is called. */

#include <iostream>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>
#include <algorithm>

class HasPtr {
friend void swap(HasPtr& lhs, HasPtr& rhs);
public:
  HasPtr(const std::string& s = std::string()): ps(new std::string(s)), i(0) {}
  HasPtr(const HasPtr& rhs): ps(new std::string(*rhs.ps)), i(rhs.i) {}
  HasPtr& operator=(HasPtr rhs);
  ~HasPtr() { delete ps; }
public:
  void swap(HasPtr& rhs);
private:
  std::string * ps;
  int i;
};

void swap(HasPtr& lhs, HasPtr& rhs);


void swap(HasPtr& lhs, HasPtr& rhs) {
  lhs.swap(rhs);
}

inline void HasPtr::swap(HasPtr &rhs) {
  using std::swap;
  swap(ps, rhs.ps);
  swap(i, rhs.i);
}

inline HasPtr& HasPtr::operator=(HasPtr rhs) {
  this->swap(rhs);
  return *this;
}
