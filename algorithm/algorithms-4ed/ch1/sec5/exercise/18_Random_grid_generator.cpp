/* 1.5.18    Random grid generator. Write a program RandomGrid that takes an int value */ 
/* N from the command line, generates all the connections in an N-by-N grid, puts them */ 
/* in random order, randomly orients them (so that p q and q p are equally likely to oc- */
/* cur), and prints the result to standard output. To randomly order the connections, use */ 
/* a RandomBag (see Exercise 1.3.34 on page 167). To encapsulate p and q in a single object, */
/* use the Connection nested class shown below. Package your program as two static */ 
/* methods:  generate(), which takes N as argument and returns an array of connec- */
/* tions, and main(), which takes N from the command line, calls generate(), and iterates */ 
/* through the returned array to print the connections. */ 

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <random>
#include "inc/UnionFind.h"

static std::vector<std::pair<int, int>> generate(const int numberOfSites) {
  std::vector<std::pair<int, int>> randomBag;
  
  for (int i = 0; i < numberOfSites; ++i) {
    for (int j = 0; j < numberOfSites; ++j) {
      if (i != j) {
        randomBag.push_back({i, j});
      }
    }
  }

  std::random_device rand_dev;
  std::mt19937 generator(rand_dev());

  std::shuffle(randomBag.begin(), randomBag.end(), generator);

  return randomBag;
}

int main(int argc, char** argv) {
  auto numberOfSites = std::stoi(argv[1]);
  std::vector<std::pair<int, int>> connections = generate(numberOfSites);

  for (const auto& connection : connections) {
    std::cout << connection.first << " - " << connection.second << "\n";
  }
  std::cout << "\n";

  return 0;
}
