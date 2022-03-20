#include <iostream>
#include <ostream>
#include <string>
#include <utility>
#include <vector>

int main() {
    std::vector<std::pair<std::string, int>> vec;
    std::string str;
    int n = 0;

    std::cout << "Enter a string and number: ";
    while (std::cin >> str >> n) {
        vec.push_back({str, n});
        vec.push_back(std::pair<std::string, int>(str, n));
        vec.push_back(std::make_pair(str, n));
        std::cout << "Enter a string and number: ";
    }

    std::cout << "\n" << std::endl;

    for (const auto& p : vec) {
        std::cout << p.first << " " << p.second << std::endl;
    }
}
