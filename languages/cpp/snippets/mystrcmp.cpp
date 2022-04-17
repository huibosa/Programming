#include <algorithm>
#include <string>

int strcmp(std::string lhs, std::string rhs) {
  if (lhs == rhs) {
    return 0;
  }
  auto n = std::min(lhs.size(), rhs.size());

  for (int i = 0; i < n; ++i) {
    if (lhs[i] < rhs[i]) {
      return -1;
    } else if (lhs[i] > rhs[i]) {
      return 1;
    }
  }
  return lhs.size() - rhs.size();
}
