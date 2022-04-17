#include "19.h"
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream input("../../data/book.txt");
    StrBlob blob;

    for (std::string line; std::getline(input, line);) {
        blob.push_back(line);
    }
    for (StrBlobPtr pbeg(blob.begin()), pend(blob.end()); pbeg != pend; pbeg.incr()) {
        std::cout << pbeg.dref() << std::endl;
    }
}
