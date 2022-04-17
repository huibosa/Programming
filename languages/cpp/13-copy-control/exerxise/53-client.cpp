#include "53_HasPtr.h"

int main()
{
    HasPtr hp1("hello"), hp2("World"), *pH = new HasPtr("World");
    hp1 = hp2;
    hp1 = std::move(*pH);
}
