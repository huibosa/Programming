#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <fstream>

class StaticSetOfInts {
public:
  StaticSetOfInts(std::vector<int> keys):
    vals(keys) { std::sort(vals.begin(), vals.end()); }
public:
  bool contains(int key) { return rank(key) != -1; }
  int rank(int key) const;
private:
  std::vector<int> vals;
};

inline int StaticSetOfInts::rank(int key) const {
  int head = 0;
  int tail = vals.size();

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

int main(int argc, char** argv) {
  std::vector<int> vals;
  auto ifstrm = std::fstream(argv[1]);
  for (int temp = 0; ifstrm >> temp; ) {
    vals.push_back(temp);
  }
  auto set = StaticSetOfInts(vals);

  for (int temp = 0; std::cin >> temp; ) {
    if (set.rank(temp) == -1) {
      std::cout << temp << "\n";
    }
  }

  return 0;
}
