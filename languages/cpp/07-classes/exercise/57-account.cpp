#pragma once

#include <string>

class Account {
public:
  void calculate() { amount = amount * interestRate; }
  static void rate(double newRate) { interestRate = newRate; }
  static double rate() { return interestRate; }
private:
  double amount;
  std::string owner;
  static double interestRate;
  static constexpr double todayRate = 1.1;
  static double initRate() { return todayRate; }
};

double Account::interestRate = initRate();
