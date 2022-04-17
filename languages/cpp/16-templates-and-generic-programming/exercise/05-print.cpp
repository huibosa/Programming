/* Exercise 16.5: Write a template version of the print function from § 6.2.4 */
/* (p. 217) that takes a reference to an array and can handle arrays of any size and any element type. */

#include <iostream>
#include <string>

template<typename _Tp> void print(const _Tp& arr) {
  for (const auto& i : arr) {
    std::cout << i << " ";
  }
  std::cout << "\n";
}

int main() {
  int a[] = { 1,2,3,4,5 };
  print(a);

  std::string b[6] = {"hello", "hasdf"};
  print(b);

  return 0;
}
