#include <algorithm>
#include <iostream>
#include <vector>

class Foo {
public:
  Foo sorted() &&;
  Foo sorted() const &;
private:
  std::vector<int> data;
};

Foo Foo::sorted() && {
  std::sort(data.begin(), data.end());
  std::cout << "&&" << "\n";

  return *this;
}

// 13.56
/* Foo Foo::sorted() const & { */
/*   Foo ret(*this); */
/*   std::cout << "const &" << "\n"; */

/*   return ret.sorted(); */
/* } */

// 13.57
Foo Foo::sorted() const & {
  return Foo(*this).sorted();
}

int main() {
  Foo().sorted();
  
  Foo foo;
  foo.sorted();

  return 0;
}
