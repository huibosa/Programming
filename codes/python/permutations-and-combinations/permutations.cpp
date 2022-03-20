#include <iostream>
#include <vector>

int main() {
  std::vector<int> a{0,1,2,3,4,5,6,7};
  int cnt = 0;

  for (int i = 0; i < a.size(); ++i) {
    for (int j = i; j < a.size(); ++j) {
      for (int k = j; k < a.size(); ++k) {
        std::cout << i << j << k << "\n";
        cnt++;
      }
    }
  }

  std::cout << cnt << "\n";

  return 0;
}
