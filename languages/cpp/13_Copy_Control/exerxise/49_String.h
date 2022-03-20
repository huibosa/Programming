/* Add a move constructor and move-assignment operator to */
/* your StrVec, String, and Message classes. */

#ifndef STRING_H
#define STRING_H

#include <cstddef>
#include <memory>
#include <string>
#include <utility>

class String {
public:
  String(): String("") {}
  String(const char *ps);
  String(const String &rhs);
  String(String&& rhs) noexcept;
  String &operator=(const String &rhs);
  String &operator=(String&& rhs) noexcept;
  ~String();

public:
  char *c_str() const { return front; }
  size_t size() { return rear - front; }
  size_t length() { return rear - front - 1; }

private:
  void free();
  std::pair<char*, char*> alloc_n_copy(char * b, char * e);

private:
  std::allocator<char> alloc;
  char *front;  // start of cstring
  char *rear;   // one past cstring end
};

#endif /* STRING_H */
