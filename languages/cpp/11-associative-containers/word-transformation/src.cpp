#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <sstream>

int main() {
    std::ifstream in_rules("rules");
    std::ifstream in_text("text");
    std::map<std::string, std::string> transform;
    std::vector<std::string> text;

    for (std::string abbr, orig; in_rules >> abbr >> orig;) {
        transform[abbr] = orig;
    }

    for (std::string line, word; getline(in_text, line);) {
        std::istringstream istring(line);
        std::ostringstream ostring;
        while (istring >> word) {
            auto found = transform.find(word);
            if (found != transform.end()) {
                ostring << transform[word] << " ";
            } else {
                ostring << word << " ";
            }
        }
        text.push_back(ostring.str());
    }

    for (const auto& line : text) {
        std::cout << line << std::endl;
    }
}
