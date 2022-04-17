#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> exclude = {"bb", "aa"};

    for (std::string word; std::cout << "Enter a word: ", std::cin >> word;) {
        auto isExcluded = std::binary_search(exclude.cbegin(), exclude.cend(), word);
        if (isExcluded) {
            std::cout << "Is exluded" << std::endl;
        }
    }
}
