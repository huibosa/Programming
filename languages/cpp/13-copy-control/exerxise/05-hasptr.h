/* Given the following sketch of a class, write a copy constructor that copies all */
/* the members. Your constructor should dynamically allocate a new string (§ */
/* 12.1.2, p. 458) and copy the object to which pspoints, rather than copying ps */
/* itself. */

#include <string>


class HasPtr {
public:
  HasPtr(const std::string& s = std::string())
    : ps(new std::string(s)), i(0) {  }
  HasPtr(const HasPtr& rhs)
    : ps(new std::string(*rhs.ps)), i(rhs.i) {  }
private:
  std::string* ps;
  int i;
};
