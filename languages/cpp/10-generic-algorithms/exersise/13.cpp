#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

bool fiveChar(std::string& s) {
    return s.size() < 5;
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
    std::vector<std::string> newStr;

    auto secPartition = std::partition(words.begin(), words.end(), fiveChar);
    std::for_each(secPartition, words.end(), [](const std::string& s)
                                                {std::cout << s << " ";});
    std::cout << "\n" << std::endl;

    std::copy(secPartition, words.end(), std::back_inserter(newStr));
    std::for_each(newStr.begin(), newStr.end(), [](const std::string& s)
                                                   {std::cout << s << " ";});
    std::cout << std::endl;
}
