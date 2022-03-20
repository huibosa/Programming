#include <algorithm>
#include <iostream>
#include <string>
#include <list>

int main() {
    std::list<std::string> slst { 
        "hello", "mother", "hello",
        "father", "son", "daughter"
    };

    auto cnt = std::count(slst.cbegin(), slst.cend(), "hello");

    std::cout << cnt << std::endl;
}
