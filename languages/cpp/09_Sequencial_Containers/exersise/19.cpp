#include <iostream>
#include <string>
#include <list>

int main() {
    std::list<std::string> text;
    std::string word;

    while (std::cin >> word) {
        text.push_back(word);
    }

    for (auto iter = text.cbegin(); iter != text.cend(); ++iter) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
}
