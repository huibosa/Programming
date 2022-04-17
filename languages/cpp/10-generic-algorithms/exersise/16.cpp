#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <iostream>

void elimDups(std::vector<std::string>& words) {
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

bool isShorter(const std::string& s1, const std::string& s2) {
    return s1.size() < s1.size();
}

void biggies(std::vector<std::string>& words, std::string::size_type sz) {
    elimDups(words);
    std::stable_sort(words.begin(), words.end(), isShorter);
    auto wc = std::find_if(words.begin(), words.end(),
                           [sz](const std::string& s) { return s.size() > sz;});

    auto count = words.cend() - wc;
    std::cout << count << " " << make_plural(count, "word", "s")
         << " of length " << sz << " or longer" << std::endl;
    for_each(wc, words.end(), [](const std::string& s) { std::cout << s << " "; });
    std::cout << std::endl;
}
