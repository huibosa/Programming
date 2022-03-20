/* Add an instnce method howMany() to StaticSETofInts (page 99) that finds the */
/* number of occurrences of a given key in time proportional to log N in the worst */
/* case */

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

class StaticSETofInts {
public:
  StaticSETofInts(std::vector<int> keys):
    vals(keys) { std::sort(vals.begin(), vals.end()); }
public:
  bool contains(int key) { return rank(key) != -1; }
  int rank(int key) const;
  int howMany(int key) const;
private:
  std::vector<int> vals;
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
