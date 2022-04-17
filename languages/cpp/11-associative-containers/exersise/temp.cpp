#include <cstddef>
#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <utility>
#include <unordered_map>
#include <unordered_set>


size_t myhasher(Sales_data& sd) {
    return std::hash<std::string>()(sd.isbn());
}

bool eqOp(const Sales_data& lhs, const Sales_data& rhs) {
    return lhs.isbn() < rhs.isbn();
}

int main() {
    std::unordered_set<Sales_data, decltype(myhasher)*, decltype(eqOp)*>
        bookStore(42, hasher, eqOp)
}
