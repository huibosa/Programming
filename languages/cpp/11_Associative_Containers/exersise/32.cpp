#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <set>

int main() {
    std::multimap<std::string, std::string> data{
        { "alan", "DMA" },
        { "pezy", "LeetCode" },
        { "alan", "CLRS" },
        { "wang", "FTP" },
        { "pezy", "CP5" },
        { "wang", "CPP-Concurrency" }
    };

    std::map<std::string, std::multiset<std::string>> order_author;

    for (const auto& item : data) {
        order_author[item.first].insert(item.second);
    }

    for (const auto& item : order_author) {
        std::cout << item.first << ": ";
        for (const auto& work : item.second) {
            std::cout << work << ", ";
        }
        std::cout << std::endl;
    }
}
