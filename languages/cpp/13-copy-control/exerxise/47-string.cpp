#include "47_String.h"
#include <utility>
#include <cstring>
#include <memory>
#include <algorithm>

String::String(const String& rhs) {
  auto data = alloc_n_copy(rhs.front, rhs.rear);
  front = data.first;
  rear = data.second;
  
  std::cout << "Copy constructor" << "\n";
}

String& String::operator=(const String &rhs) {
  auto data = alloc_n_copy(rhs.front, rhs.rear);
  
  free();
  
  front = data.first;
  rear = data.second;
  
  std::cout << "Copy-assignment constructor" << "\n";

  return *this;
}

String::String(const char* s) {
  auto b = const_cast<char*>(s);
  auto e = b + strlen(s) + 1;
  auto data = alloc_n_copy(b, e);

  front = data.first;
  rear = data.second;
}

String::~String() {
  free();
}

std::pair<char*, char*> String::alloc_n_copy(char * b, char * e) {
  auto data = alloc.allocate(e - b);

  return {data, std::uninitialized_copy(b, e, data)};
}

void String::free() {
  if (front) {
    std::for_each(front, rear, [this](char& c) { alloc.destroy(&c); });
    alloc.deallocate(front, size());
  }
}
