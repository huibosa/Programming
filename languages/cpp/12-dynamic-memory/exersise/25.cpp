#include <iostream>
#include <memory>

int main() {
    int* p = new int[10];
    delete [] p;
}
