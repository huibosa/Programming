#include <iostream>
#include <memory>

int main() {
    std::unique_ptr<int> p1(new int(42));
    std::unique_ptr<int> p2 = p1;
}
