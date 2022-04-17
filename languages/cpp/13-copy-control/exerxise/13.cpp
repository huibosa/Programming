/* A good way to understand copy-control members and constructors is to define a */
/* simple class with these members in which each member prints its name: */

// struct X {
//     X() {std::cout << "X()" << std::endl;}
//     X(const X&) {std::cout << "X(const X&)" << std::endl;}
// };

/* Add the copy-assignment operator and destructor to X and write a program using */
/* X objects in various ways: Pass them as nonreference and reference parameters; */
/* dynamically allocate them; put them in containers; and so forth. Study the output */
/* until you are certain you understand when and why each copy-control member is */
/* used. As you read the output, remember that the compiler can omit calls to the */
/* copy constructor. */

#include <iostream>
#include <vector>

struct X {
  X() { std::cout << "X()" << "\n"; }
  ~X() { std::cout << "~X()" << "\n"; }
  X(const X&) { std::cout << "X(const X&)" << "\n"; }
  X& operator=(const X&) {
    std::cout << "X& operator=(const X&)" << "\n";
    return *this;
  }
};

void foo(const X& rx, X x) {
  std::vector<X> vec;
  vec.reserve(2);
  vec.push_back(rx);
  vec.push_back(x);
}

int main() {
  /* X x; */
  /* foo(x, x); */
  
  X * px = new X;
  foo(*px, *px);
  delete px;

  return 0;
}
