#include <cstddef>
#include <iostream>
#include <istream>
#include <ostream>
#include <string>
#include <vector>

class Date {
  friend bool operator==(const Date &lhs, const Date &rhs);
  friend bool operator!=(const Date &lhs, const Date &rhs);
  friend bool operator<(const Date &lhs, const Date &rhs);
  friend bool operator>(const Date &lhs, const Date &rhs);
  friend Date &operator>>(std::istream &is, const Date &rhs);
  friend Date &operator<<(std::ostream &os, const Date &rhs);
  friend bool check(const Date &date);

public:
  Date() = default;
  Date(size_t d);
  Date(size_t d, size_t m, size_t y) : day(d), month(m), year(y) {}
  Date(std::istream &is, std::ostream &os);
  Date(const Date &that);
  Date(Date &&that);
  Date &operator=(const Date &rhs);
  Date &operator=(Date &&rhs);
  ~Date() { std::cout << "Destroying" << "\n"; }

public:
  size_t toDays() const;
  size_t operator+=(const Date &rhs);
  size_t operator-=(const Date &rhs);

private:
  size_t day = 1;
  size_t month = 1;
  size_t year = 0;
};

bool operator==(const Date &lhs, const Date &rhs);
bool operator!=(const Date &lhs, const Date &rhs);
bool operator<(const Date &lhs, const Date &rhs);
bool operator>(const Date &lhs, const Date &rhs);
Date &operator>>(std::istream &is, const Date &rhs);
Date &operator<<(std::ostream &os, const Date &rhs);
bool check(Date &date);

static const size_t YtoD_400 = 146097; // 365*400 + 400/4 -3 == 146097
static const size_t YtoD_100 = 36524;  // 365*100 + 100/4 -1 ==  36524
static const size_t YtoD_4 = 1461;     // 365*4 + 1          ==   1461
static const size_t YtoD_1 = 365;      // 365

// normal year
static const std::vector<size_t> monthsVec_n = {31, 28, 31, 30, 31, 30,
                                                31, 31, 30, 31, 30, 31};

// leap year
static const std::vector<size_t> monthsVec_l = {31, 29, 31, 30, 31, 30,
                                                31, 31, 30, 31, 30, 31};


bool check(const Date &d);
inline bool isLeapYear(size_t y);

inline bool check(const Date &d) {
  if (d.month == 0 || d.month > 12)
    return false;
  else {
    //    month == 1 3 5 7 8 10 12
    if (d.month == 1 || d.month == 3 || d.month == 5 || d.month == 7 ||
        d.month == 8 || d.month == 10 || d.month == 12) {
      if (d.day == 0 || d.day > 31)
        return false;
      else
        return true;
    } else {
      //    month == 4 6 9 11
      if (d.month == 4 || d.month == 6 || d.month == 9 || d.month == 11) {
        if (d.day == 0 || d.day > 30)
          return false;
        else
          return true;
      } else {
        //    month == 2
        if (isLeapYear(d.year)) {
          if (d.day == 0 || d.day > 29)
            return false;
          else
            return true;
        } else {
          if (d.day == 0 || d.day > 28)
            return false;
          else
            return true;
        }
      }
    }
  }
}

inline bool isLeapYear(size_t y) {
  if (!(y % 400)) {
    return true;
  } else {
    if (!(y % 100)) {
      return false;
    } else
      return !(y % 4);
  }
}
