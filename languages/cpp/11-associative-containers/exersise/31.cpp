#include <iostream>
#include <map>
#include <string>

int main() {
    std::multimap<std::string, std::string> table{
        {"huibosa", "apple"}, {"huibosa", "orange"},
        {"makima", "pineapple"}, {"makima", "coconut"},
    };

    auto author = "huibosa";
    auto work = "apple";

    auto found = table.find(author);
    auto count = table.count(author);

    while (count) {
        if (found->second == work) {
            table.erase(found);
            break;
        }
        ++found;
        --count;
    }

}
