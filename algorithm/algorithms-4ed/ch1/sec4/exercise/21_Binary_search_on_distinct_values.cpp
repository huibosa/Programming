/* Binry search on distinct values. Develop an implementation of binary search */
/* for StaticSETofInts (see page 98) where the running time of contains() is guaranteeda */
/* to b ~ lg R, where R is the number of different integers in the array given as argument */
/* to the constructor.e */

/* use a set */


#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <set>

class StaticSETofInts {
public:
  StaticSETofInts(const std::vector<int>& keys);
public:
  bool contains(int key) const { return rank(key) != -1; };
  int rank(int key) const;
  int howMany(int key) const;
private:
  std::vector<int> vals;
};

inline StaticSETofInts::StaticSETofInts(const std::vector<int>& keys)  {
  std::set<int> set(keys.cbegin(), keys.cend());
  vals.assign(set.begin(), set.end());
};

inline int StaticSETofInts::rank(int key) const {
  int head = 0;
  int tail = vals.size() - 1;

  while (head <= tail) {
    auto mid = head + (tail - head) / 2;
    if (vals[mid] > key) {
      tail = mid - 1;
    } else if (vals[mid] < key) {
      head = mid + 1;
    } else {
      return mid;
    }
  }
  return -1;
};

inline int StaticSETofInts::howMany(int key) const {
  int ret = 0;
  int head = 0;
  int tail = vals.size() - 1;

  while (head <= tail) {
    auto mid = head + (tail - head) / 2;
    if (vals[mid] > key) {
      tail = mid - 1;
    } else if (vals[mid] < key) {
      head = mid + 1;
    } else {
      ret++;
    }
  }
  return -1;
};

