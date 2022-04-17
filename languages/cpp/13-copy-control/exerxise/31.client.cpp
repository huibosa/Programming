#include <vector>
#include <algorithm>
#include "31_HasPtr.h"

int main() {
  HasPtr s("s");
  HasPtr a("a");
  HasPtr c("c");
  std::vector<HasPtr> vec {s, a, c};
  
  std::sort(vec.begin(), vec.end());

  return 0;
}
