#include <iostream>
#include <memory>
#include <string>

int main() {
    std::allocator<std::string> alloc;

    auto beg = alloc.allocate(10);
    auto ptr = beg;
    for (std::string temp; std::cin >> temp && ptr != beg + 10;) {
        alloc.construct(ptr++, temp);
    }
    auto size = ptr - beg;
    std::cout << size << std::endl;
    for (; ptr != beg; --ptr) {
        alloc.destroy(ptr);
    }
    alloc.deallocate(beg, 10);

}
