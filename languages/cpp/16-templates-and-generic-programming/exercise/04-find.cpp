/* Write a template that acts like the library find algorithm.  The function
 * will */
/* need two template type parameters, one to represent the function’s iterator
 */
/* parameters and the other for the type of the value. Use your function to find
 * a */
/* given value in a vector<int> and in a list<string>. */

#include <iostream>
#include <list>
#include <string>
#include <vector>


template <typename _Tp1, typename _Tp2>
_Tp1 find(_Tp1 begin, _Tp1 end, _Tp2 val) {
  for (/* empty */; begin != end && *begin != val; ++begin) {
    continue;
  }
  return begin;
}

int main() {
  std::vector<int> vi{1, 2, 3, 4, 5, 6};
  auto p1 = find(vi.begin(), vi.end(), 5);
  std::cout << (p1 != vi.end() ? "Found" : "Not Found") << "\n";

  std::list<std::string> ls{"hello", "world", "love"};
  auto p2 = find(ls.begin(), ls.end(), "a");
  std::cout << (p2 != ls.end() ? "Found" : "Not Found") << "\n";

  return 0;
}
