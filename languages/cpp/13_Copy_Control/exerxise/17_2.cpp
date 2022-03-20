#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>

struct numbered {
  numbered() {
    mysn = unique++;
  }

  numbered(const numbered& n) {
    mysn = unique++;
  }
  
  int mysn;
  static int unique;
};

int numbered::unique = 10;

void foo(numbered s) {
  std::cout << s.mysn << "\n";
}

int main() {
  numbered a;
  numbered b = a;
  numbered c = b;

  foo(a);
  foo(b);
  foo(c);

  return 0;
}
