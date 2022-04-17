#include <iostream>
#include <iterator>
#include <list>
#include <forward_list>

void process_data(std::list<int>& lst) {
    for (auto iter = lst.begin(); iter != lst.end(); ) {
        if (*iter & 0x01) {
            iter = lst.insert(iter, *iter);
            std::advance(iter, 2);
        }
        else {
            iter = lst.erase(iter);
        }
    }
}

void process_data(std::forward_list<int>& flst) {
    for (auto prev = flst.before_begin(), cur = flst.begin(); cur != flst.end(); ) {
        if (*cur & 0x01) {
            prev = flst.insert_after(prev, *cur);
            ++cur;
            ++prev;
        }
        else {
            cur = flst.erase_after(prev);
        }
    }
}

int main() {
    std::list<int> lst{0,1,2,3,4,5,6,7,8,9};
    std::forward_list<int> flst{0,1,2,3,4,5,6,7,8,9};

    // process_data(lst);
    process_data(flst);

    for (const auto& i : lst) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    for (const auto& i : flst) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
