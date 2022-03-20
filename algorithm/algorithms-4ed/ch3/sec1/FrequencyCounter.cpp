#include "SequencialSearchST.h"
#include <iostream>
#include <string>

int main(int argc, char** argv) {
  int minLen = std::stoi(argv[1]);
  SequentialSearchST<std::string, int> st;

  for (std::string word; std::cin >> word; ) {
    if (word.size() < minLen) {
      continue;
    }
    
    if (!st.contains(word)) {
      st.put(word, 1);
    } else {
      st.put(word, st.get(word) + 1);
    }
  }

  std::string max = " ";
  st.put(max, 0);
  for (const auto& word : st.keys()) {
    if (st.get(word) > st.get(max)) {
      max = word;
    }
  }

  std::cout << max << " " << st.get(max) << "\n";

  return 0;
}
