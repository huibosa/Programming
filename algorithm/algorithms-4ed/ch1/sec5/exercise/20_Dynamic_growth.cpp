/* 1.5.20  Dynamic growth. Using linked lists or a resizing array, develop a weighted */ 
/* quick-union implementation that removes the restriction on needing the number of */ 
/* objects ahead of time. Add a method newSite() to the API, which returns an int */

#include <stdexcept>
#include <vector>
#include <iostream>
#include <array>

class UnionFind {
public:
  UnionFind() = default;
public:
  void connect(int site1, int site2);
  int count() const { return cnt; }
  int getNumberOfSites() { return numberOfSite; }
  bool isConnected(int site1, int site2) const;
  int findRoot(int site) const;
  int newSite();
private:
  std::vector<int> id; // site indexed array
  std::vector<int> sz; // size of component for roots (site indexed)
  int cnt = 0;         // number of components
  int numberOfSite = 0;
};


inline bool UnionFind::isConnected(int site1, int site2) const {
  if (id.empty() || site1 >= numberOfSite || site2 >= numberOfSite ) {
    throw std::runtime_error("Site does not exits");
  }
  return findRoot(site1) == findRoot(site2);
};

inline int UnionFind::findRoot(int site) const {
  if (id.empty() || site >= numberOfSite) {
    throw std::runtime_error("Site does not exits");
  }
  
  while (site != id[site]) {
    site = id[site];
  }
  return site;
};

inline void UnionFind::connect(int site1, int site2) {
  if (id.empty() || site1 >= numberOfSite || site2 >= numberOfSite ) {
    throw std::runtime_error("Site does not exits");
  }
  
  int root1 = findRoot(site1);
  int root2 = findRoot(site2);
  
  if (root1 == root2) { return; }
  
  --cnt;
  
  if (sz[root1] < sz[root2]) {
    id[root1] = root2;
    sz[root2] += sz[root1];
  } else {
    id[root2] = root1;
    sz[root1] += sz[root2];
  }
};

inline int UnionFind::newSite() {
  auto size = id.size();
  id.push_back(size);
  sz.push_back(1);
  
  ++cnt;
  ++numberOfSite;

  return size;
};

int main() {
  UnionFind unionFind;

  for (int i = 0; i < 1000; ++i) {
    unionFind.newSite();
  }

  while (unionFind.count() != 1) {
    auto randomSite1 = rand() % unionFind.getNumberOfSites();
    auto randomSite2 = rand() % unionFind.getNumberOfSites();

    if (!unionFind.isConnected(randomSite1, randomSite2)) {
      unionFind.connect(randomSite1, randomSite2);

      std::cout << "United sites " << randomSite1 << " and " << randomSite2 << "\n";
    }
  }
}
