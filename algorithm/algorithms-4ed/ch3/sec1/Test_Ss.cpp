#include <iostream>
#include "SequencialSearchST.h"
#include <string>

int main() {
  SequentialSearchST<std::string, int> st;

  std::string key;
  for (int i = 0; std::cin >> key; ++i) {
    st.searchCount = 0;
    st.put(key, i);
    std::cout << st.searchCount << "\n";
  }

  // for (const auto& k : st.keys()) {
  //   std::cout << k << " " << st.get(k) << "\n";
  // }

  return 0;
}
