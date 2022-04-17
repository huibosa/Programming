/* Write the assignment operator for the HasPtr class from exercise 13.5 in § */
/* 13.1.1 (p. 499). As with the copy constructor, your assignment operator should */
/* copy the object to which ps points. */

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
