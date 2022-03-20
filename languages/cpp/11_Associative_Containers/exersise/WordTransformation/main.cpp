#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <map>
#include <vector>
#include <sstream>

std::map<std::string, std::string> buildMap(std::ifstream& map_file) {
    std::map<std::string, std::string> retval;

    for (std::string key, value; map_file >> key && getline(map_file, value);) {
        if (value.size() > 1) {
            retval[key] = value.substr(1);
        }
        else {
            throw std::runtime_error("no rule for " + key);
        }
    }

    return retval;
}

const std::string transform(const std::string& s, const std::map<std::string, std::string>& m) {
    auto found = m.find(s);
    if (found != m.end()) {
        return found->second;
    }
    else {
        return s;
    }
}

void word_transform(std::ifstream& map_file, std::ifstream& input) {
    auto trans_map = buildMap(map_file);

    for (std::string word, line; std::getline(input, line);) {
        std::istringstream isstrm(line);
        std::ostringstream osstrm;
        while (isstrm >> word) {
            osstrm << transform(word, trans_map) << " ";
        }
        std::cout << osstrm.str() << std::endl;
    }
}

int main() {
    std::ifstream map_file("rules");
    std::ifstream input("text");

    word_transform(map_file, input);
}
