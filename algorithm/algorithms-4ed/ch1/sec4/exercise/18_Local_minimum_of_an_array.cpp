#include <iostream>
#include <vector>
#include <algorithm>

const auto NOT_FOUND = -9999;

int localMininum(std::vector<int> vals) {
  auto head = 0;
  auto tail = vals.size() - 1;

  if (vals.size() == 1) {
    return vals[0];
  }

  if (vals.size() == 2) {
    return (vals[1] < vals[2] ? vals[1] : vals[2]);
  }

  while (head <= tail) {
    auto mid = head + (tail - head) / 2;

    if (mid == 0) {
      if (vals[mid] < vals[mid+1]) {
        return vals[mid];
      } else {
        return NOT_FOUND;
      }
    }

    if (mid == vals.size() - 1) {
      if (vals[mid] < vals[mid-1]) {
        return vals[mid];
      } else {
        return NOT_FOUND;
      }
    }

    if (vals[mid-1] > vals[mid] && vals[mid+1] > vals[mid]) {
      return vals[mid];
    } else if (vals[mid-1] < vals[mid]) {
      tail = mid - 1;
    } else if (vals[mid+1] < vals[mid]) {
      head = mid + 1;
    }
  }

  return NOT_FOUND;
}


int main() {
  std::vector<int> vals{5,2,3,2,2,7,6};

  std::cout << localMininum(vals) << "\n";


  return 0;
}
