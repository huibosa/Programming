#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <fstream>
#include <sstream>

int main() {
    std::ifstream input("Alice.txt");
    std::string target = "a";
    std::size_t lineCount = 0;
    std::vector<std::string> text;
    std::map<std::string, std::set<std::size_t>> oline;
    // store the entire text
    for (std::string line; std::getline(input, line);) {
        text.push_back(line);
    }

    for (const auto& s : text) {
        lineCount += 1;
        std::istringstream istrm(s);
        for (std::string word; istrm >> word; ) {
            oline[word].insert(lineCount);
        }
    }

    for (auto iter = oline.cbegin(); iter != oline.cend(); ++iter) {
        std::cout << iter->first << " occurs " << iter->second.size()
                  << " times" << std::endl;
        for (const auto& ix : iter->second) {
            std::cout <<  "\t(line " << ix << ") " << text[ix-1] << std::endl;
        }
        std::cout << std::endl;
    }
}
