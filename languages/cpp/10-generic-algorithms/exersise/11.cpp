#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

void elimDups(std::vector<std::string>& v) {
    std::sort(v.begin(), v.end());
    auto end_unique = std::unique(v.begin(), v.end());
    v.erase(end_unique, v.end());
}

bool isShorter(const std::string& s1, const std::string& s2) {
    return s1.size() < s2.size();
}

int main() {
    std::vector<std::string> v {
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

    elimDups(v);
    std::stable_sort(v.begin(), v.end(), isShorter);

    std::for_each(v.cbegin(), v.cend(), [](const std::string& s) { std::cout << s << " "; });
    std::cout << std::endl;
}
