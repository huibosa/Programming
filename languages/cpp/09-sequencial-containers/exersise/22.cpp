/* Exercise 9.22: Assuming iv is a vector of ints, what is wrong with the */
/* following program? How might you correct the problems */

// vector<int>::iterator iter = iv.begin(),
//                       mid = iv.begin() + iv.size()/2;
// while (iter != mid)
//     if (*iter == some_val)
//         iv.insert(iter, 2 * some_val);
 
 
#include <iostream>
#include <vector>

void double_and_insert(std::vector<int>& v, int some_val) {
    auto mid = [&]{ return v.begin() + v.size() / 2; };
    for (auto curr = v.begin(); curr != mid(); ++curr)
        if (*curr == some_val)
            ++(curr = v.insert(curr, 2 * some_val));
}

int main() {
    std::vector<int> v{ 1, 9, 1, 9, 9, 9, 1, 1 };
    double_and_insert(v, 1);

    for (auto i : v) 
        std::cout << i << " ";

    return 0;
}
