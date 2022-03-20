#include <iostream>
#include <map>
#include <vector>
#include <string>

using Families = std::map<std::string, std::vector<std::string>>;

auto make_families() {
    Families families;

    for (std::string ln; std::cout << "Last name:\n", std::cin >> ln && ln != "@q";) {
        for (std::string cn; std::cout << "First name\n", std::cin >> cn && cn != "@q";) {
            families[ln].push_back(cn);
        }
    }
    return families;
}

auto print(Families const& families) {
    for (const auto& family : families) {
        std::cout << family.first << ":\n";
        for (const auto& child : family.second) {
            std::cout << child << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    print(make_families());
    return 0;
}
