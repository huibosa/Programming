/* Exercise 9.28: Write a function that takes a forward_list<string> and */
/* two additional string arguments. The function should find the first string */
/* and insert the second immediately following the first. If the first string is */
/* not found, then insert the second string at the end of the list. */

#include <iostream>
#include <string>
#include <forward_list>

void find_insert(std::forward_list<std::string>& flst, const std::string& s1,
                                                       const std::string& s2) {
     auto prev = flst.before_begin();
     auto cur = flst.begin();

     while (cur != flst.end()) {
         if (*cur == s1) {
             cur = flst.insert_after(cur, s2);
             ++prev;
             break;
         }
         else {
             prev = cur;
             ++cur;
         }
     }
     if (cur == flst.end()) {
         flst.insert_after(prev, s2);
     }
}

/*
void find_and_insert(forward_list<string> &list, string const& to_find, string const& to_add)
{
    auto prev = list.before_begin();
    for (auto curr = list.begin(); curr != list.end(); prev = curr++)
    {
        if (*curr == to_find)
        {
            list.insert_after(curr, to_add);
            return;
        }
    }
    list.insert_after(prev, to_add);
}
*/

int main() {
    std::forward_list<std::string> flst{"hello", "world"};

    find_insert(flst, "a", "beautiful");

    for (const auto& s : flst) {
        std::cout << s << std::endl;
    }
}
