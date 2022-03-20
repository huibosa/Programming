#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> wc;
    std::string word;

    while (std::cin >> word) {
        auto ret = wc.insert({word, 1});
        if (!ret.second) {
            ++(ret.first->second);
        }
    }
}
