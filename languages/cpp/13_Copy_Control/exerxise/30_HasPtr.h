/* Write and test a swap function for your valuelike version of */
/* HasPtr. Give your swap a print statement that notes when it is executed. */

#include <iostream>
#include <string>
#include <type_traits>
#include <utility>

class HasPtr {
friend void swap(HasPtr&, HasPtr&);
public:
  HasPtr(const std::string& s = std::string()): ps(new std::string(s)), i(0) {  }
  HasPtr(const HasPtr& rhs): ps(new std::string(*rhs.ps)), i(rhs.i) {  }
  HasPtr& operator=(const HasPtr& rhs);
  ~HasPtr() { delete ps; }
private:
  std::string* ps;
  int i;
};

inline HasPtr& HasPtr::operator=(const HasPtr &rhs) {
  auto temp = new std::string(*rhs.ps);
  
  delete this->ps;
  this->ps = temp;
  this->i = rhs.i;

  return *this;
}

inline void swap(HasPtr& lhs, HasPtr& rhs) {
  using std::swap;
  swap(lhs.i, rhs.i);
  swap(lhs.ps, rhs.ps);
  std::cout << "call swap(HasPtr& lhs, HasPtr& rhs)" << std::endl;
}
