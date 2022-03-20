#include <functional>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

void elimdups(std::vector<std::string> &vs) {
    std::sort(vs.begin(), vs.end());
    auto new_end = std::unique(vs.begin(), vs.end());
    vs.erase(new_end, vs.end());
}

bool check_size(const std::string& s, std::string::size_type sz) {
    return s.size() > sz;
}

void biggies_bind(std::vector<std::string> &vs, std::string::size_type sz) {
    elimdups(vs);
    
    auto pivot = std::partition(vs.begin(), vs.end(),
                                std::bind(check_size, std::placeholders::_1, sz));
    
    for(auto it = vs.cbegin(); it != pivot; ++it)
        std::cout << *it << " ";
}

int main() {
    std::vector<std::string> words {
        "men", "remember", "love", "because", "of",
        "romance", "only", "when", "working", "with",
        "tabular", "data", "such", "as", "data",
        "stored", "in", "spreadsheets", "or", "databases",
        "pandas", "is", "the", "right", "tool", "for", "you",
        "pandas", "will", "help", "you", "to", "explore",
        "clean", "a", "process", "you", "data", "in",
        "pandas", "a", "data", "table", "is", "called", "a",
        "dataframe"
    };
    biggies_bind(words, 6);
}
