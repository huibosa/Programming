#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "Date.h"
#include <istream>
#include <ostream>
#include <string>

class Transaction {
  friend bool operator==(const Transaction &lhs, const Transaction &rhs);
  friend bool operator!=(const Transaction &lhs, const Transaction &rhs);
  friend bool operator>(const Transaction &lhs, const Transaction &rhs);
  friend bool operator<(const Transaction &lhs, const Transaction &rhs);
  friend std::ostream &operator<<(std::ostream &os, const Transaction &rhs);

public:
  Transaction(std::string _who, Date _when, double _amount)
      : who(_who), when(_when), amount(_amount){};
  Transaction(const std::string &transaction);

public:
  std::string getWho() const;
  Date getWhen() const;
  double getAmount() const;

private:
  std::string toString() const;
  int hasCode() const;

private:
  std::string who;
  Date when;
  double amount;
};

#endif /* TRANSACTION_H */
