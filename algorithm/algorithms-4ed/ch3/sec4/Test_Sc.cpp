#include <iostream>
#include "SeparateChainingHashST.h"
#include <string>

int main() {
  SeparateChainingHashST<std::string, int> st(1543);

  std::string key;
  for (int i = 0; std::cin >> key; ++i) {
    st.put(key, i);
  }

  /* for (const auto& k : st.keys()) { */
  /*   std::cout << k << " " << st.get(k) << "\n"; */
  /* } */

  return 0;
}
