#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>

using Families = std::map<std::string, std::vector<std::pair<std::string, std::string>>>;

auto make_families() {
    Families families;

    for (std::string ln; std::cout << "Last name:\n", std::cin >> ln && ln != "@q";) {
        for (std::string cn, bday; std::cout << "First name\n", std::cin >> cn && cn != "@q",
                             std::cout << "Birthday\n", std::cin >> bday && bday != "@q";) {
            families[ln].push_back({cn, bday});
        }
    }
    return families;
}

auto print(Families const& families) {
    for (const auto& family : families) {
        std::cout << family.first << ":\n";
        for (const auto& child : family.second) {
            std::cout << child.first << " " << child.second;
        }
        std::cout << std::endl;
    }
}

int main() {
    print(make_families());
    return 0;
}
