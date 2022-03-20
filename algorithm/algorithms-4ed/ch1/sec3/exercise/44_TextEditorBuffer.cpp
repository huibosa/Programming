#include <iostream>
#include <memory>
#include <stack>
#include <list>

class Buffer {
public:
  Buffer() = default;
public:
  void insert(char c);
  char erase();
  void goLeft(int k);
  void goRight(int k);
  int size() const { return left.size() + right.size(); }
  void print() const;
private:
  void printLeft() const;
  void printRight() const;
private:
  std::stack<char> left;
  std::stack<char> right;
};

inline void Buffer::insert(char c) {
  left.push(c);
};

inline char Buffer::erase() {
  auto ret = left.top();
  left.pop();

  return ret;
};

inline void Buffer::goLeft(int k) {
  int count = 0;

  while (count < k && left.size() > 0) {
    right.push(left.top());
    left.pop();

    count++;
  }
};

inline void Buffer::goRight(int k) {
  int count = 0;

  while (count < k && right.size() > 0) {
    left.push(right.top());
    right.pop();

    count++;
  }
};

inline void Buffer::print() const {
  printLeft();
  std::cout << "|";
  printRight();
  std::cout << std::endl;
};

inline void Buffer::printLeft() const {
  auto pv = std::make_shared<std::list<char>>();

  auto temp = left;
  while (!temp.empty()) {
    auto ch = temp.top();
    pv->push_front(ch);
    temp.pop();
  }

  for (const auto& c : *pv) {
    std::cout << c;
  }
};

inline void Buffer::printRight() const {
  auto temp = right;

  while (!temp.empty()) {
    std::cout << temp.top();
    temp.pop();
  }
};

int main() {
  Buffer buffer;
  buffer.insert('a');
  buffer.insert('b');
  buffer.insert('c');
  buffer.insert('d');
  buffer.goLeft(2);
  buffer.insert('e');
  buffer.goRight(1);
  buffer.insert('f');
  buffer.goLeft(3);
  buffer.erase();
  buffer.print();

  return 0;
}
