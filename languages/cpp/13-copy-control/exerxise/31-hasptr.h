/* Give your class a < operator and define a vector of */
/* HasPtrs. Give that vector some elements and then sort the vector. */
/* Note when swap is called. */

#include <algorithm>
#include <iostream>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>

class HasPtr {
  friend void swap(HasPtr &, HasPtr &);
  friend bool operator<(const HasPtr &, const HasPtr &);

public:
  HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
  HasPtr(const HasPtr &rhs) : ps(new std::string(*rhs.ps)), i(rhs.i) {}
  HasPtr &operator=(HasPtr rhs);
  ~HasPtr() { delete ps; }

public:
  void swap(HasPtr &rhs);

private:
  std::string *ps;
  int i;
};

void swap(HasPtr &, HasPtr &);
bool operator<(const HasPtr &, const HasPtr &);

inline void swap(HasPtr &lhs, HasPtr &rhs) { lhs.swap(rhs); }

inline void HasPtr::swap(HasPtr &rhs) {
  using std::swap;
  swap(i, rhs.i);
  swap(ps, rhs.ps);
  std::cout << "call swap(HasPtr& lhs, HasPtr& rhs)" << std::endl;
}

inline HasPtr &HasPtr::operator=(HasPtr rhs) {
  this->swap(rhs);
  return *this;
}

inline bool operator<(const HasPtr &lhs, const HasPtr &rhs) {
  return *lhs.ps < *rhs.ps;
}
