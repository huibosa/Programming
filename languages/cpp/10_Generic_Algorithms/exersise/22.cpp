#include <functional>
#include <algorithm>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

bool six_or_less(const std::string& s, std::string::size_type sz) {
    return s.size() <= sz;
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

    auto wc = std::count_if(words.begin(), words.end(),
                            std::bind(six_or_less, std::placeholders::_1, 6));
    std::cout << wc << std::endl;
}
