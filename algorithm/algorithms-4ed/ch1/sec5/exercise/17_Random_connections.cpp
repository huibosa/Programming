/* 1.5.17    Random connections. Develop a UF client ErdosRenyi that takes an integer */ 
/* value N from the command line, generates random pairs of integers between 0 and N-1, */ 
/* calling connected() to determine if they are connected and then union() if not (as in */ 
/* our development client), looping until all sites are connected, and printing the number */ 
/* of connections generated. Package your program as a static method count() that takes */ 
/* N as argument and returns the number of connections and a main() that takes N from */ 
/* the command line, calls count(), and prints the returned value. */

#include <iostream>
#include <string>
#include <utility>
#include "inc/UnionFind.h"

static int count(int numberOfSites, bool verbose) {
  auto connectionsGenerated = 0;

  UnionFind unionFind(numberOfSites);
  while (unionFind.count() != 1) {
    auto randomSite1 = rand() % numberOfSites;
    auto randomSite2 = rand() % numberOfSites;

    ++connectionsGenerated;

    if (verbose) {
      std::cout << "Connection generated: "
                << randomSite1 << " - " << randomSite2 << "\n";
    }

    if (!unionFind.isConnected(randomSite1, randomSite2)) {
      unionFind.connect(randomSite1, randomSite2);
    }
  }

  return connectionsGenerated;
}

static int erdosRenyi(int numberOfSites, bool verbose) {
  return count(numberOfSites, verbose);
}

int main(int argc, char** argv) {
  auto numberOfSites = std::stoi(argv[1]);
  auto numberOfConnections = erdosRenyi(numberOfSites, true);

  std::cout << "\n";
  std::cout << "Number of connections generated: " << numberOfConnections << "\n";
}
