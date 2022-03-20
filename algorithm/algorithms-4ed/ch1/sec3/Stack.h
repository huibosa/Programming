#pragma once
#include <iostream>
#include <memory>

class Stack {
public:
  using Item = int;
  Stack() = default;
public:
  void push(Item item);
  void pop();
  Item peek() const;
  bool isEmpty() const { return sz == 0; }
  int size() const { return sz; }
  Item top() const { return first->item; }
private:
  class Node {
  public:
    Node(Item n): item(n) {  }
    Item item = 0;
    Node* next = nullptr;
  };
private:
  Node* first = nullptr;
  int sz = 0;
};

inline void Stack::push(Item item) {
  auto pnew = new Node(item);

  if (this->isEmpty()){
    first = pnew;
  } else {
    pnew->next = first;
    first = pnew;
  }
  ++sz;
};

inline void Stack::pop() {
  if (this->isEmpty()) {
    std::cout << "Stack is empty" << std::endl;
  } else {
    while (!this->isEmpty()) {
      auto temp = first;
      first = first->next;
      delete temp;
      --sz;
    }
  }
};

inline Stack::Item Stack::peek() const {
  if (this->isEmpty()) {
    std::cout << "Empty stack" << std::endl;
    std::exit(1);
  } else {
    return first->item;
  }
};

