/* Add a move constructor and move-assignment operator to */
/* your StrVec, String, and Message classes. */

#ifndef STRVEC_H
#define STRVEC_H

#include <cstddef>
#include <initializer_list>
#include <memory>
#include <string>
#include <utility>

class StrVec {
public:
  StrVec() = default;
  StrVec(const StrVec &rhs);
  StrVec(StrVec&& rhs) noexcept;
  StrVec(std::initializer_list<std::string> init);
  StrVec &operator=(const StrVec &rhs);
  StrVec &operator=(StrVec && rhs) noexcept;
  ~StrVec();

public:
  void push_back(const std::string &str);
  size_t size() const { return pivot - front; }
  size_t capacity() const { return rear - front; }
  void reserve(size_t n);
  void resize(size_t n) { resize(n, std::string()); }
  void resize(size_t n, const std::string& t);
  std::string *begin() const { return front; }
  std::string *end() const { return pivot; }

private:
  void check_n_alloc();
  std::pair<std::string *, std::string *> alloc_n_copy(const std::string *,
                                                       const std::string *);
  void free();
  void reallocate();
  void alloc_n_move(size_t n);

private:
  std::allocator<std::string> alloc;
  std::string *front;
  std::string *pivot;
  std::string *rear;
};

#endif /* STRVEC_H */
