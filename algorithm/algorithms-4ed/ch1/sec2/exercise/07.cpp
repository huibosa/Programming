#include <iostream>
#include <string>

std::string mystery(std::string s) {
  int size = s.size();
  if (size <= 1) { return s; }
  std::string a = s.substr(0, size/2);
  std::string b = s.substr(size/2, size);

  return mystery(b) + mystery(a);
}

int main() {
  std::cout << mystery("hello") << std::endl;
}
