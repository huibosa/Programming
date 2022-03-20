#include "24_Date.h"
#include <cstddef>
#include <istream>
#include <ostream>

Date::Date(size_t days) {
  auto year = days / 365;
}


Date::Date(std::istream& is, std::ostream& os) {
  
};

bool operator==(const Date& lhs, const Date& rhs) {
  if (lhs.day == rhs.day
      && lhs.month == rhs.month
      && lhs.year == rhs.year) {
    return true;
  }
  return false;
}

bool operator!=(const Date& lhs, const Date& rhs) {
  return !(lhs == rhs);
}
