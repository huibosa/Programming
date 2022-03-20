/* Exercise 9.25: In the program on page 349 that erased a range of */
/* elements, what happens if elem1 and elem2 are equal? What if elem2 or */
/* both elem1 and elem2 are the off-the-end iterator? */

#include <algorithm>
#include <array>
#include <iterator>
#include <iostream>
#include <string>
#include <vector>
#include <list>

int main() {
    std::vector<int> v{1,2,3};
    auto elem1 = v.end();
    auto elem2 = v.end();

    v.erase(elem1, elem2);

    std::for_each(v.cbegin(), v.cend(), [](const int& i) { std::cout << i << " "; });
    std::cout << std::endl;
}
