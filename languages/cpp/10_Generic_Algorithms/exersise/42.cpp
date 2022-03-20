#include <algorithm>
#include <list>
#include <iostream>
#include <string>
#include <iterator>

void elimDumps(std::list<std::string>& words) {
    words.sort();
    words.unique();
}

int main() {
    std::list<std::string> lst{
        "g","g","k","k","e","e","d","d",
        "b","b","g","g","u","u","a","a",
        "x","x","b","e","e","n","n"};
    elimDumps(lst);
    
    std::copy(lst.cbegin(),lst.cend(), std::ostream_iterator<std::string>(std::cout, " "));
}
