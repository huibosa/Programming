#include <cstdlib>
#include <iostream>
#include <string>
#include <memory>
#include <stack>

const int CAP = 1000;

class FixedCapacityStackOfStrings {
public:
  FixedCapacityStackOfStrings(int cap);
  virtual ~FixedCapacityStackOfStrings();
public:
  void push(std::string item);
  void pop();
  bool isEmpty() const { return n == 0; }
  bool isFull() const { return n == capacity; }
  int size() const { return n; }
private:
  std::string* p = nullptr;
  int n = 0;
  int capacity;
};

inline FixedCapacityStackOfStrings::FixedCapacityStackOfStrings(int cap) {
  capacity = cap;
  p = new std::string[cap]();
};

inline void FixedCapacityStackOfStrings::push(std::string item) {
  if (n <= capacity){
    p[n++] = item;
  }
};

inline void FixedCapacityStackOfStrings::pop() {
  --n;
}
