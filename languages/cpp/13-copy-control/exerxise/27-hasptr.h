//  Define your own reference-counted version of HasPtr. 

#include <iostream>
#include <string>

class HasPtr {
public:
  HasPtr(const std::string &s = std::string())
      : ps(new std::string(s)),i(0), useCount(new int(1)) {  }
  HasPtr(const HasPtr& rhs)
      : ps(new std::string(*rhs.ps)), i(rhs.i), useCount(new int(++(*rhs.useCount))) {}
  HasPtr& operator=(const HasPtr& rhs);
  ~HasPtr();
private:
  std::string * ps;
  int i;
  int *useCount;
};

inline HasPtr& HasPtr::operator=(const HasPtr &rhs) {
  ++(*useCount);    // handle self assignment
  if (--(*useCount) <= 0) {
    delete ps;
    delete useCount;
  }

  ps = rhs.ps;
  i = rhs.i;
  useCount = rhs.useCount;

  return *this;
}

inline HasPtr::~HasPtr() {
  if (--(*useCount) <= 0) {
    delete ps;
    delete useCount;
  }
}
