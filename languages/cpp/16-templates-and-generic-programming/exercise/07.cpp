/* 16.7: Write a constexpr template that returns the size of a given */
/* array. */
 
#include <cstddef>
#include <iostream>
#include <string>

template<typename _Tp, size_t N>
constexpr size_t getArraySize(const _Tp (&)[N]) {
  return N;
}

int main() {
  int a[] = {1,2,3,4};
  std::string s[] = {"sss"};

  std::cout << getArraySize(a) << "\n";
  std::cout << getArraySize(s) << "\n";

  return 0;
}
