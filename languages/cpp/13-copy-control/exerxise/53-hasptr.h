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
public:
  friend void swap(HasPtr &, HasPtr &);
  HasPtr(const std::string &s = std::string());
  HasPtr(const HasPtr &rhs);
  HasPtr(HasPtr &&rhs) noexcept;
  HasPtr &operator=(HasPtr rhs);
  ~HasPtr();

private:
  std::string *ps;
  int i;
};
