#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

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
    auto cnt = std::count_if(words.begin(), words.end(),
                                [](const std::string& s) { return s.size() > 6; });
    std::cout << cnt << std::endl;
}
