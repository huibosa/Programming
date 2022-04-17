#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

bool isShorter(const std::string& s1,  const std::string& s2) {
    return s1.size() < s2.size();
}

void elimDumps(std::vector<std::string>& v) {
    std::sort(v.begin(), v.end());
    auto end_unique = std::unique(v.begin(), v.end());
    v.erase(end_unique, v.end());
}

void biggies(std::vector<std::string>& words, std::string::size_type sz) {
    elimDumps(words);
    std::stable_sort(words.begin(), words.end(), isShorter);
    auto wc = std::find_if(words.begin(), words.end(),
                           [sz](const std::string& a) {return a.size() > sz;});
    std::for_each(wc, words.end(),
                    [](std::string& s) { std::cout << s << " "; });
}

int main() {
    std::vector<std::string> v = {
        "the",   "quick", "red", "fox",
        "jumps", "over",  "the", "slow",
        "red",   "turtle"
    };

}
