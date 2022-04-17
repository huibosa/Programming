#include <iostream>
#include <string>

class PointerToString {
public:
  class PtPts {
  public:
    PtPts(PointerToString& s) : r(s) {}

  public:
    std::string* operator->() {
      std::cout << "inderect dereference"
                << "\n";
      return &*r;
    }

  private:
    PointerToString& r;
  };

public:
  PointerToString(const std::string& s) : a(s) {}
  PtPts operator->() {
    std::cout << "arrow dereference"
              << "\n";
    return *this;
  }
  std::string& operator*() {
    std::cout << "dereference"
              << "\n";
    return a;
  }

private:
  std::string a;
};

int main() {
  PointerToString        ptr(std::string("hello"));
  std::string::size_type size = ptr->size();

  return 0;
}
