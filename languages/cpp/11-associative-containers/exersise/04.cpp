#include <cctype>
#include <iostream>
#include <map>
#include <string>
#include <algorithm>


void strip(std::string& word) {
    for (auto& c : word) { c = tolower(c); }
    word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
}


int main() {
    std::map<std::string, std::size_t> wc;
    std::string word;

    while (std::cin >> word) {
        strip(word);
        ++wc[word];
    }

    for (const auto& w : wc) {
        std::cout << w.first << " shows " << w.second
                  << (w.second > 1 ? " times" : " time") << std::endl;
    }
}

