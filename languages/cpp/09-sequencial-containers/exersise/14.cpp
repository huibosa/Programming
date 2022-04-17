#include <iostream>
#include <list>
#include <vector>
#include <string>

int main() {
    std::list<const char*> lst = { "hello", "world" };
    std::vector<std::string> vec;

    vec.assign(lst.cbegin(), lst.cend());

    for (const auto& s : vec) {
        std::cout << s << " ";
    }
    std::cout << std::endl;
}
