#include <cstdio>
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include "Date.h"
#include "Transaction.h"
#include "MinPQ.h"

int main(int argc, char** argv) {
  const int M = std::stoi(argv[1]);
  MinPQ<Transaction> pq(M);
  
  std::string line;
  while (std::getline(std::cin, line)) {
    pq.insert(Transaction(line));
    if (pq.size() > M) {
      pq.delMin();
    }
  } // Top M entries are on the PQ
  
  std::vector<Transaction> vector;
  while (!pq.empty()) {
    vector.push_back(pq.delMin());
  }
  
  for (Transaction t : vector) {
    std::cout << t << "\n";
  }

  return 0;
}
