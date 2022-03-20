#include <cstdio>
#include <iostream>
#include <string>
#include <stack>
#include "Date.h"
#include "Transaction.h"

template <typename _Tp> class MinPQ;
class Transaction;

int main(int argc, char** argv) {
  const int M = std::stoi(argv[1]);
  MinPQ<Transaction> pq;
  
  std::string line;
  while (std::getline(std::cin, line)) {
    pq.insert(Transaction(line));
    if (pq.size() > M) {
      pq.delMin();
    }
  } // Top M entries are on the PQ
  
  std::stack<Transaction> stack;
  while (!pq.empty()) {
    stack.push(pq.delMin());
  }
  
  for (Transaction t : stack) {
    std::cout << t << "\n";
  }

  return 0;
}
