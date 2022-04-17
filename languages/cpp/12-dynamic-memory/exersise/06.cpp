#include <iostream>
#include <ostream>
#include <vector>
#include <memory>

auto make_dynamically() {
    return new std::vector<int>{};
}

auto populate(std::vector<int>* pv) {
    for (int i; std::cin >> i;) {
        pv->push_back(i);
    }
    return pv;
}

auto print(std::vector<int>* pv) -> std::ostream& {
    for (const auto& i : *pv) {
        std::cout << i << " ";
    }
    return std::cout;
}

int main() {
    auto pv = populate(make_dynamically());
    print(pv) << std::endl;
    delete pv;
}
