#include <cstdio>
#include <ctime>
#include <iostream>
#include <memory>
#include <list>

using Item = int;

class Node {
public:
  Node(Item i): item(i) {  }
public:
  Node* next = nullptr;
  Item item;
};  

class List {
public:
  List() = default;
public:
  void push(Item item);
public:
  Node* first = nullptr;
};

inline void List::push(Item item) {
  auto pnew = new Node(item);

  if (first == nullptr) {
    first = pnew;
  } else {
    auto cur = first;
    while (cur->next != nullptr) {
      cur = cur->next;
    }
    cur->next = pnew;
  }
};

Node *reverse_iterative(Node *x) {
  auto first = x;
  Node* ret = nullptr;

  while (first != nullptr) {
    auto temp = first->next;
    first->next = ret;
    ret = first;
    first = temp;
  }
  return ret;
}

Node* revsese_recursive(Node* first) {
  if (first == nullptr) { return nullptr; }
  if (first->next == nullptr) { return first; }

  auto temp = first->next;
  auto rest = revsese_recursive(temp);
  temp->next = first;
  first->next = nullptr;

  return rest;
}

int main() {
  List lst;

  for (int i = 0; i < 10; ++i) {
    lst.push(i);
  }

  auto p = lst.first;
  while (p != nullptr) {
    std::cout << p->item << " ";
    p = p->next;
  }
  std::cout << std::endl;

  auto result = reverse_iterative(lst.first);

  while (result != nullptr) {
    std::cout << result->item << " ";
    result = result->next;
  }
  std::cout << std::endl;

  return 0;
}
