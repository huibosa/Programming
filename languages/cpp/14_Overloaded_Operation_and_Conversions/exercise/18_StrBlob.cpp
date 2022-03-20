#include "18_StrBlob.h"
#include <memory>
#include <string>
#include <utility>
#include <vector>

bool operator==(const StrBlob& lhs, const StrBlob& rhs) {
  return *lhs.data == *rhs.data;
}

bool operator!=(const StrBlob& lhs, const StrBlob& rhs) {
  return !(lhs == rhs);
}

bool operator<(const StrBlob& lhs, const StrBlob& rhs) {
  return *lhs.data < *lhs.data;
}

bool operator>(const StrBlob& lhs, const StrBlob& rhs) {
  return *lhs.data > *lhs.data;
}

bool operator==(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs) {
  return lhs.curr == rhs.curr;
}

bool operator!=(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs) {
  return !(lhs == rhs);
}
 
///////////////////////////////////////////////////////////////////////////

StrBlob& StrBlob::operator=(const StrBlob& rhs) {
  data = std::make_shared<std::vector<std::string>>(*rhs.data);
  return *this;
};

StrBlob& StrBlob::operator=(StrBlob&& rhs) noexcept {
  if (this != &rhs) {
    data = std::move(rhs.data);
    rhs.data = nullptr;
  }

  return *this;
};


///////////////////////////////////////////////////////////////////////////

StrBlobPtr StrBlob::begin() {
  return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end() {
  return StrBlobPtr(*this, data->size());
}

ConstStrBlobPtr StrBlob::cbegin() const {
  return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::cend() const {
  return ConstStrBlobPtr(*this, data->size());
}
