/* Define a class that holds a pointer to a StrBlobPtr. */
/* Define the overloaded arrow operator for that class. */

#include <memory>

class StrBlobPtr;

class StrBlobPtr_pointer {
public:
  StrBlobPtr_pointer() = default;
  StrBlobPtr_pointer(StrBlobPtr* p): pointer(p) {  }
public:
  StrBlobPtr& operator*() const;
  StrBlobPtr* operator->() const;
private:
  StrBlobPtr* pointer = nullptr;
};
