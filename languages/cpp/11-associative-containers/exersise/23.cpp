#include <iostream>
#include <map>
#include <vector>
#include <string>

using Families = std::multimap<std::string, std::string>;

auto make_families() {
    Families families;
    std::string ln;
    std::string fn;

    while (std::cin >> ln >> fn) {
        families.insert({ln, fn});
    }
    return families;
}

auto print(const Families& families) {
    for (const auto& family : families) {
        std::cout << family.first << " " << family.second
                  << std::endl;
    }
}

int main() {
    print(make_families());
    return 0;
}
