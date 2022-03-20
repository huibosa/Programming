#include <iostream>
#include <vector>

int count(const std::vector<int>& a) {
  int N = a.size();
  int cnt = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      for (int k = j + 1; k < N ; ++k) {
        if (a[i] + a[j] + a[k] == 0) {
          cnt++;
        }
      }
    }
  }
  return cnt;
}

int main() {
  std::vector<int> a;

  int temp = 0;
  while (std::cin >> temp) {
    a.push_back(temp);
  }

  std::cout << count(a) << std::endl;

  return 0;
}
