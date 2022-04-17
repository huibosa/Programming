/* Add a destructor to your HasPtr class from the previous exercises. */


#include <iostream>
#include <string>

class HasPtr {
public:
  HasPtr(const std::string& s = std::string()): ps(new std::string(s)), i(0) {  }
  HasPtr(const HasPtr& rhs): ps(new std::string(*rhs.ps)), i(rhs.i) {  }
  HasPtr& operator=(const HasPtr& rhs);
  ~HasPtr();
private:
  std::string* ps;
  int i;
};

inline HasPtr::~HasPtr() {
  delete ps;
}

inline HasPtr& HasPtr::operator=(const HasPtr &rhs) {
  if (this != &rhs) {
    delete this->ps;
    this->ps = new std::string(*rhs.ps);
    this->i = rhs.i;
  }

  return *this;
}
