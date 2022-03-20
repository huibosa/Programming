#include <iostream>
#include <string>

// ACTGACG
// TGACGAC

bool isCircularShift(const std::string& s, const std::string& t) {
  return s.size() == t.size() && (s+s).find(t) != std::string::npos;
}

int main() {
  std::string s = "ACTGACG";
  std::string t = "TGACGAC";

  std::cout << (isCircularShift(s, t) ? "true" : "false")
            << std::endl;
}
