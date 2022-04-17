#include "21_Sales_data.h"
#include <algorithm>
#include <string>

Sales_data::Sales_data(std::istream& is) {
  is >> *this;
}

Sales_data& Sales_data::operator+=(const Sales_data &rhs) {
  *this = *this + rhs;
  return *this;
};

std::istream& operator>>(std::istream& is, Sales_data& item) {
  double price = 0.0f;
  is >> item.bookNo >> item.units_sold >> price;
  
  if (is) {
    item.revenue = price * item.units_sold;
  } else {
    item = Sales_data();
  }
  
  return is;
};

std::ostream& operator<<(std::ostream& os, const Sales_data& item) {
  os << item.isbn() << " "
     << item.units_sold << " "
     << item.revenue << " "
     << item.avg_price();

  return os;
}

Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs) {
  Sales_data ret;
  ret.revenue = lhs.revenue + rhs.revenue;
  ret.units_sold = lhs.units_sold + rhs.units_sold;

  return ret;
}
