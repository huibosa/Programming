#include <iostream>
#include "LinearProbingHashST.h"
#include <string>

int main() {
  LinearProbingHashST<std::string, int> st;

  std::string key;
  for (int i = 0; std::cin >> key; ++i) {
    st.put(key, i);
  }
  
  // for (const auto& k : st.keys()) {
  //   std::cout << k << " " << st.get(k) << "\n";
  // }

  return 0;
}
