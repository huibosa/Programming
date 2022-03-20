#include <forward_list>
#include <cstddef>
#include <iostream>
#include <memory>

class Node {
public:
  Node(int i): item(i) {  }
public:
  int item;
  Node* prev = nullptr;
  Node* next = nullptr;
};

class DoubleNode {
public:
  DoubleNode() = default;
public:
  void push_front(int item);
  void push_back(int item);
  void pop_front();
  void pop_back();
  Node& front() { return *head; }
  Node& back() { return *tail; }
  Node& front() const { return *head; }
  Node& back() const { return *tail; }
  void insert_before(int item);
  void insert_after(int item);
  bool is_empty() const { return sz == 0; }
  std::size_t size() const { return sz; }
private:
  Node* head = nullptr;
  Node* tail = nullptr;
  std::size_t sz = 0;
};

inline void DoubleNode::push_front(int item) {
  auto pn = new Node(item);

  if (this->is_empty()) {
    head = pn;
    tail = pn;
  } else {
    auto temp = head->next;
    head = pn;
    pn->next = temp;
  }
};

inline void DoubleNode::push_back(int item) {
  auto pn = new Node(item);

  ++sz;
  if (this->is_empty()) {
    head = pn;
    tail = pn;
  } else {
    tail->next = pn;
  }
};

inline void DoubleNode::pop_front() {
  if (this->is_empty()) {
    std::cerr << "Empty list!" << std::endl;
    return;
  } else {
    auto temp = head->next;
    head = head->next;
    delete temp;
  }
};

inline void DoubleNode::pop_back() {
  if (this->is_empty()) {
    std::cerr << "Empty list!" << std::endl;
    return;
  } else {

  }
};
