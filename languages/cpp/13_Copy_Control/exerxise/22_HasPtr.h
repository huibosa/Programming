/* Assume that we want HasPtr to behave like a value. That */
/* is, each object should have its own copy of the string to which the objects */
/* point. We’ll show the definitions of the copy-control members in the next */
/* section. However, you already know everything you need to know to */
/* implement these members. Write the HasPtr copy constructor and copy- */
/* assignment operator before reading on. */

#include <iostream>
#include <string>

class HasPtr {
public:
  HasPtr(const std::string& s = std::string()): ps(new std::string(s)), i(0) {  }
  HasPtr(const HasPtr& rhs): ps(new std::string(*rhs.ps)), i(rhs.i) {  }
  HasPtr& operator=(const HasPtr& rhs);
private:
  std::string* ps;
  int i;
};

inline HasPtr& HasPtr::operator=(const HasPtr &rhs) {
  if (this != &rhs) {
    delete this->ps;
    this->ps = new std::string(*rhs.ps);
    this->i = rhs.i;
  }

  return *this;
}
