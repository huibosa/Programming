#include <iostream>
#include <memory>

void process(std::shared_ptr<int> ptr) {
    std::cout << "inside the process function: " << ptr.use_count() << std::endl;
}

int main() {
    std::shared_ptr<int> p(new int(42));
    process(std::shared_ptr<int>(p.get()));

    std::cout << p.use_count() << std::endl;
    // std::cout << "the int p now points to is: " << *p << std::endl;
    return 0;
}
