#include <iostream>
#include <algorithm>
#include <memory>
#include <array>
#include <vector>

class CC {
public:
  CC() = default;
public:
  int countChange(int amount, int kind);
private:
  std::array<int, 5> denomination{1, 5, 10, 25, 10};
};

inline int CC::countChange(int amount, int kind) {
  if (amount == 0) { return 1; }
  if (amount < 0 || kind == 0) { return 0; }

  return countChange(amount, kind - 1) + countChange(amount - denomination[kind - 1], kind);
};

int main() {
  CC cc;
  std::cout << cc.countChange(1000, 5) << "\n";

  return 0;
}
