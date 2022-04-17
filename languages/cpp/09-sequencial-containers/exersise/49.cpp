#include <cstdio>
#include <iostream>
#include <string>
#include <fstream>

int main() {
    std::string ascender{"bdfhiklt"};
    std::string descender{"gjpqy"};
    std::ifstream ifstrm("Alice.txt");
    std::string word;
    std::string largest;

    while (ifstrm >> word) {
        if ((word.find_first_of(ascender + descender) == std::string::npos) &&
             word.size() > largest.size()) {
            largest = word;
        }
    }

    std::cout << largest << std::endl;
}
