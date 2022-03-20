#include <cstdlib>
#include <vector>
#include <iostream>


int main() {
  std::vector<int> a;
  for (int i = 0; i < 1000; ++i) {
    a.push_back(rand() % 10000);
  }
  
  /* for (int i = 0; i < 1000000; ++i) { */
  /*   for (int i = 1; i < a.size(); ++i) { */
  /*     std::swap(a[i-1], a[i]); */
  /*   } */
  /* } */
  
  for (int i = 0; i < 1000000; ++i) {
    for (int i = 1; i < a.size(); ++i) {
      auto temp = a[i-1];
      a[i-1] = a[i];
      a[i] = temp;
    }
  }
}
