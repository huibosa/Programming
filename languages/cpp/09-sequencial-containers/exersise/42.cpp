#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string s;
    char c;
    s.reserve(100);

    while (std::cin >> c) {
        s.push_back(c);
    }

    std::cout << s << std::endl;
}
