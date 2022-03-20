#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<char> c{'H','e','l','l','o'};
    std::string s(c.begin(), c.end());

    std::cout << s << std::endl;
}
