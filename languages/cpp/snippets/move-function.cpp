#include <algorithm>
#include <vector>
#include <iostream>

class A {
public:
    A(A && rhs) noexcept : val(rhs.val) { std::cout << "Move constructor." << "\n"; }
    A(const A& rhs): val(rhs.val) { std::cout << "Copy constructor" << "\n"; }
    A& operator=(A && rhs) noexcept;
    A& operator=(const A & rhs);
    A(int i): val(i) { std::cout << "hello" << "\n"; }
private:
    int val = 0;
};

A& A::operator=(A && rhs) noexcept {
    val = rhs.val;
    std::cout << "Move-assignmemnt constructor." << "\n";
    return *this;
}

A& A::operator=(const A & rhs) {
    val = rhs.val;
    std::cout << "Copy-assignmemnt constructor." << "\n";
    return *this;
}

A foo() {
    std::cout << "******" << "\n";
    A ret(5);
    std::cout << "******" << "\n";

    return ret;
}

int main() {
    A a = foo();

    return 0;
}
