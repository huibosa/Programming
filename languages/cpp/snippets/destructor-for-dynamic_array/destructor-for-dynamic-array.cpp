#include <iostream>
#include <memory>

struct A {
  std::shared_ptr<int*> vals;
  
  A(): vals(new int*[10]) {
    for (int i = 0; i < 10; ++i) {
      *(vals+i) = new int;
    }
  }
  
  ~A(){
    delete [] vals;
  }
};

int main() {
  A a;
  {
    A temp;
    for (int i = 0; i < 10; ++i) {
      temp.vals[i] = new int(1);
    }
    a.vals = temp.vals;
    temp.vals = nullptr; // avoid double free
  }
  for (int i = 0; i < 10; ++i) {
    std::cout << *a.vals[i] << "\n";
  }
  
}
