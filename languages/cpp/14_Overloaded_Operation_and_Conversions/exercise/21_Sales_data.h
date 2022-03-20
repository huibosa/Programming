/* Exercise 14.21: Write the Sales_data operators so that + does the actual */
/* addition and += calls +. Discuss the disadvantages of this approach compared */
/* to the way these operators were defined in § 14.3 (p. 560) and § 14.4 (p. */
/* 564). */

#pragma once

#include <istream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iostream>

class Sales_data {
friend std::istream& operator>>(std::istream&, Sales_data&); // input
friend std::ostream& operator<<(std::ostream&, const Sales_data&); // output
friend Sales_data operator+(const Sales_data&, const Sales_data&); // addition
public:
  Sales_data(const std::string& s, unsigned n, double p)
        : bookNo(s), units_sold(n), revenue(n*p) {  }
  Sales_data(): Sales_data("", 0, 0.0f) {  }
  Sales_data(const std::string& s): Sales_data(s, 0, 0.f) {  }
  Sales_data(std::istream& is);
public:
  Sales_data& operator+=(const Sales_data&);
  std::string isbn() const { return bookNo; }
private:
  double avg_price() const;
private:
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

std::istream& operator>>(std::istream&, Sales_data&);
std::ostream& operator<<(std::ostream&, const Sales_data&);
Sales_data operator+(const Sales_data&, const Sales_data&);

inline double Sales_data::avg_price() const {
  return units_sold ? revenue/units_sold : 0;
};
