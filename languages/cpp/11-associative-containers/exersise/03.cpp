#include <iostream>
#include <map>
#include <string>

auto& count(std::map<std::string, std::size_t>& wc) {
    for (std::string word; std::cin >> word;) {
        ++wc[word];
    }
    return wc;
}

void print(std::map<std::string, std::size_t>& wc) {
    for (const auto& w : wc) {
        std::cout << w.first << " shows " << w.second
                  << (w.second > 1 ? " times" : " time") << std::endl;
    }
}

int main() {
    std::map<std::string, std::size_t> wc;

    print(count(wc));
}

