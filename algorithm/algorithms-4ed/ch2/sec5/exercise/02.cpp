#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

std::vector<std::string> getCompoundWord(std::vector<std::string> wordList) {
  std::sort(wordList.begin(), wordList.end());
  std::unordered_set<std::string> wordSet(wordList.begin(), wordList.end());
  std::vector<std::string> retval;
  
  for (int i = 0; i < wordList.size(); ++i) {
    for (int j = i + 1; j < wordList.size(); ++j) {
      if (wordList[j].find(wordList[i]) != std::string::npos) {
        std::string restOfWord = wordList[j].substr(wordList[i].size());
        if (wordSet.find(restOfWord) != wordSet.end()) {
          retval.push_back(wordList[j]);
        }
      } else {
        break;
      }
    }
  }
  return retval;
}

int main() {
  std::vector<std::string> wordList;

  for (std::string word; std::cin >> word; ) {
    wordList.push_back(word);
  }

  auto res = getCompoundWord(wordList);

  for (const auto& word : res) {
    std::cout << word << "\n";
  }

  return 0;
}
