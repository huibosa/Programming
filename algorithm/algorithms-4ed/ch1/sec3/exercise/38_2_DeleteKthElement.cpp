#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <memory>

class Node {
public:
  using Item = std::size_t;
  Node(Item n): item(n) {  }
public:
  Item item = 0;
  Node* next = nullptr;
};

class Stack {
public:
  Stack() = default;
public:
  void insert(Node::Item item);
  void deleteKth();
  bool isEmpty() const { return sz == 0; }
  std::size_t size() const { return sz; }
private:
  Node* head = nullptr;
  std::size_t sz = 0;
};

inline void Stack::insert(Node::Item item) {
  auto pnew = new Node(item);

  if (this->isEmpty()){
    head = pnew;
  } else {
    pnew->next = head;
    head = pnew;
  }
  ++sz;
};

inline void Stack::deleteKth() {
  if (this->isEmpty()) {
    std::cout << "Stack is empty" << std::endl;
  } else {
    while (!this->isEmpty()) {
      auto temp = head;
      head = head->next;
      delete temp;
      --sz;
    }
  }
};

int main() {
  auto ps = std::make_shared<Stack>();

  for (std::size_t i = 0; i < 9999; ++i) {
    ps->insert(i);
  }

  while (!ps->isEmpty()) {
    ps->deleteKth();
  }

  return 0;
}
