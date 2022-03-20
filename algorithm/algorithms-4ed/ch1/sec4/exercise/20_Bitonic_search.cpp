#include <iostream>
#include <algorithm>
#include <vector>

bool binarySearch(const std::vector<int>& vals, int head, int tail, int n){
  auto temp = vals;
  std::sort(temp.begin(), temp.end());

  while (head <= tail) {
    auto mid = head + (tail - head) / 2;
    if (n < temp[mid]) {
      tail = mid - 1;
    }
    else if (n > temp[mid]) {
      head = mid + 1;
    } else {
      return true;
    }
  }
  return false;
}

bool bitotic_search(const std::vector<int>& vals, const int n) {
  auto head = 0;
  auto tail = vals.size() - 1;

  if (vals.size() == 2) {
    return (vals[0] == n || vals[1] == n);
  }

  while (head <= tail) {
    auto mid = head + (tail - head) / 2;

    if (vals[mid] == n) {
      return true;
    }

    if (n < vals[mid]) {
      // monotonically increasing
      if (vals[mid-1] < vals[mid] && vals[mid] < vals[mid+1]) {
        return binarySearch(vals, head, mid - 1, n);
      }
      // monotonically decreasing
      else if (vals[mid-1] > vals[mid] && vals[mid] > vals[mid+1]) {
        tail = mid - 1;
        continue;
      }
      // maximum value
      else if (vals[mid] > vals[mid-1] && vals[mid] > vals[mid+1]) {
        auto res1 =  binarySearch(vals, head, mid - 1, n);
        auto res2 =  binarySearch(vals, mid + 1, tail, n);

        return (res1 || res2);
      }
    }
    else if (n > vals[mid]) {
      // monotonically increasing
      if (vals[mid-1] < vals[mid] && vals[mid] < vals[mid+1]) {
        head = mid + 1;
        continue;
      }
      // monotonically decreasing
      else if (vals[mid-1] > vals[mid] && vals[mid] > vals[mid+1]) {
        return binarySearch(vals, mid + 1, tail, n);
      }
      // maximum value
      else if (vals[mid] > vals[mid-1] && vals[mid] > vals[mid+1]) {
        auto res1 =  binarySearch(vals, head, mid - 1, n);
        auto res2 =  binarySearch(vals, mid + 1, tail, n);

        return (res1 || res2);
      }
    }
  }

  return false;
}

int main() {
  std::vector<int> vec1{1,2,3,4,-1,-2,-3};
  std::vector<int> vec2{1,5,4,3,2,0};
  std::vector<int> vec3{2,4,8,16,32,1};
  std::vector<int> vec4{2,4,8,16,32};
  std::vector<int> vec5{2,1};
  std::vector<int> vec6{9};

  std::cout << bitotic_search(vec1, -1) << "\n";
  std::cout << bitotic_search(vec2, 5) << "\n";
  std::cout << bitotic_search(vec3, 2) << "\n";
  std::cout << bitotic_search(vec3, 99) << "\n";
  std::cout << bitotic_search(vec4, 32) << "\n";
  std::cout << bitotic_search(vec5, 1) << "\n";
  std::cout << bitotic_search(vec6, 9) << "\n";

  return 0;
}
