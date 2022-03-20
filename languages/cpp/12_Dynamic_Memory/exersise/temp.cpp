#include <algorithm>
#include <cstdio>
#include <ios>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <new>
#include <memory>

int main() {
    std::vector<int> vi{0,1,2,3,4,5};
    std::allocator<int> alloc;

    auto p = alloc.allocate(vi.size() * 2);
    auto q = std::uninitialized_copy(vi.cbegin(), vi.cend(), p);
    std::uninitialized_fill_n(q, vi.size(), 0);
}
