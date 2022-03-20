#include <list>
#include <memory>
#include <iostream>

struct Node {
  Node() = default;
  Node(int i): item(i), prev(nullptr), next(nullptr) {}
  int item = 0;
  struct Node* prev = nullptr;
  struct Node* next = nullptr;
};

class Steque {
public:
  Steque(): head(new Node()), tail(new Node()) {}
  ~Steque();
public:
  void push(const int item);
  void pop();
  void enquene(const int item);
  int size() const { return sz; };
  bool empty() const { return size() == 0; }
private:
  Node* head = nullptr;
  Node* tail = nullptr;
  int sz = 0;
};

inline Steque::~Steque() {
  delete head;
  delete tail;
}

inline void Steque::push(const int item) {
  auto pnew = new Node(item);
  
  if (this->empty()) {
    head = pnew;
    tail = pnew;
  }
  else {
    head->prev = pnew;
    pnew->next = head;
    head = pnew;
  }
  
  ++sz;
};

inline void Steque::pop() {
  if (this->empty()) {
    std::cout << "empty!" << "\n";
    return;
  }
  else if (sz == 1) {
    delete head;
    head = nullptr;
    tail = nullptr;
  }
  else {
    auto second = head->next;
    /* delete head; */
    second->prev = nullptr;
    head = second;
  }
};

inline void Steque::enquene(const int item) {
  auto pnew = new Node(item);
  if (this->empty()) {
    head->prev = pnew;
    pnew->next = head;
    head = pnew;
  }
  else {
    tail->next = pnew;
    pnew->prev = tail;
    tail = pnew;
  }
  sz++;
};

int main() {
  while (1) {
    Steque st;
  }
  
  /* st.push(1); */
  /* std::cout << st.size() << "\n"; */
  
  /* st.enquene(2); */
  /* std::cout << st.size() << "\n"; */

  /* st.pop(); */
  /* std::cout << st.size() << "\n"; */
  

  return 0;
}
