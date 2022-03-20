/* 1.1.28 Remove duplicates. Modify the test client in BinarySearch to remove any du- */
/* plicate keys in the whitelist after the sort. */

#include <iostream>
#include <vector>
#include <algorithm>

void removeDuplicate(std::vector<int>& vec) {
  int ix = 0;
  for (int iv = ix + 1; iv < vec.size(); iv++) {
    if (vec[ix] != vec[iv]) {
      if (vec[ix] != vec[iv]) {
        ix++;
        vec[ix] = vec[iv];
      }
    }
  }
  vec.erase(vec.begin() + ix + 1, vec.end());
}

int main() {
  std::vector<int> vec{1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9};

  removeDuplicate(vec);

  for (const auto& i : vec) {
    std::cout << i << std::endl;
  }
}
