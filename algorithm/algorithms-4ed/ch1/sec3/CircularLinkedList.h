// this circular linked list is implemented by singly linked list
#pragma once

#include <iostream>
#include <memory>
#include <initializer_list>
#include <stdexcept>

class CircularLinkedList {
public:
  using Item = int;
  CircularLinkedList() = default;
  CircularLinkedList(std::initializer_list<Item> il);
public:
  void push_back(Item item);
  void pop_front();
  void catenation(const CircularLinkedList* that);
  void display() const;
  Item back() const { return rear->item; }
  bool isEmpty() const { return sz == 0; }
  int size() const { return sz; }
private:
  class Node {
  public:
    Node(Item n): item(n) {  }
  public:
    Item item = 0;
    Node* next = nullptr;
  };
private:
  Node* rear = nullptr;
  int sz = 0;
};

inline CircularLinkedList::CircularLinkedList(std::initializer_list<CircularLinkedList::Item> il)  {
  for (const auto& i : il) {
    this->push_back(i);
    sz++;
  }
};

inline void CircularLinkedList::push_back(Item item) {
  auto pn = new Node(item);

  if (this->isEmpty()) {
    rear = pn;
    pn->next = pn;
  } else {
    auto temp = rear->next;

    rear->next = pn;
    rear = pn;
    pn->next = temp;
  }
};

inline void CircularLinkedList::pop_front() {
  if (this->isEmpty()) {
    throw std::runtime_error("Empty list\n");
  }

  auto front = rear->next;
  rear->next = front->next;
  delete front;
};

inline void CircularLinkedList::catenation(const CircularLinkedList* that) {
  auto thisFront = this->rear->next;
  auto thatFront = that->rear;
  while (thatFront->next != that->rear) {
    thatFront = thatFront->next;
  }
  this->rear->next = that->rear;
  thatFront->next = thisFront;
};

inline void CircularLinkedList::display() const {
  auto cur = rear;
  while (cur->next != rear) {
    std::cout << cur->item << "->";
    cur = cur->next;
  }
  std::cout << cur->item << std::endl;
};
