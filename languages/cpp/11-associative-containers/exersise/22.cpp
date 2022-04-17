#include <map>
#include <string>
#include <utility>
#include <vector>

int main() {
    std::map<std::string, std::vector<int>> c;
    c.insert(std::map<std::string, std::vector<int>>::value_type("a", {1,2}));
    c.insert(std::pair<std::string, std::vector<int>>("a", {1,2}));

    std::pair<std::map<std::string, std::vector<int>>::iterator, bool> ret
        = c.insert(std::make_pair(std::string("a"), std::vector<int>{1,2}));
}
