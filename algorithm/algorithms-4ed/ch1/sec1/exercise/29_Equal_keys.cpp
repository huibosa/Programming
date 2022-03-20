/* 1.1.29 Equal keys. Add to BinarySearch a static method rank() that takes a key and */
/* a sorted array of int values (some of which may be equal) as arguments and returns the */
/* number of elements that are smaller than the key and a similar method count() that */
/* returns the number of elements equal to the key. Note : If i and j are the values returned */
/* by rank(key, a) and count(key, a) respectively, then a[i..i+j-1] are the values in */
/* the array that are equal to key. */


#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
  Solution() = default;

public:
  auto rank(int val, std::vector<int> vec);
  auto count(int val, std::vector<int> vec);
};

inline auto Solution::rank(int val, std::vector<int> vec) {
  auto ret = 0;

  /* auto pivot = std::unique(vec.begin(), vec.end()); */
  /* vec.erase(pivot, vec.end()); */

  for (const auto& i : vec) {
    if (i < val) {
      ret++;
    }
  }
  return ret;
}

inline auto Solution::count(int val, std::vector<int> vec) {
  auto ret = 0;

  /* auto pivot = std::unique(vec.begin(), vec.end()); */
  /* vec.erase(pivot, vec.end()); */

  for (const auto& i : vec) {
    if (i == val) {
      ret++;
    }
  }

  return ret;
}

int main() {
  Solution sln;

  std::vector<int> vec{1,1,2,2,4,6,8};
  std::cout << sln.rank(4, vec) << std::endl;
  std::cout << sln.count(4, vec) << std::endl;
}
