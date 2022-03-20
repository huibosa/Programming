#include <iostream>
#include <map>
#include <list>
#include <string>

auto makeMap() {
    std::map<std::string, std::list<std::size_t>> wordOccur;
    std::string word;
    for (std::size_t i = 1; std::cin >> word;) {
        wordOccur[word].push_back(i++);
    }

    return wordOccur;
}

void print(const std::map<std::string, std::list<std::size_t>>& wo) {
    for (const auto& word : wo) {
        std::cout << word.first << " ";
        for (const auto& line : word.second) {
            std::cout << line << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    print(makeMap());
}
