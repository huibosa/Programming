#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> wc;
    std::string word;

    while (std::cin >> word) {
        ++wc.insert({word, 0}).first->second;
    }

    for (const auto& w : wc) {
        std::cout << w.first << ": " << w.second;
        std::cout << std::endl;
    }
}
