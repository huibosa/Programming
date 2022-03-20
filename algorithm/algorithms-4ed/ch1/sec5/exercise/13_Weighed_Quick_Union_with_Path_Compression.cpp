/* 1.5.13       Weighted quick-union with path compression. Modify weighted quick-union */ 
/* (Algorithm 1.5) to implement path compression, as described in Exercise 1.5.12. */ 
/* Give a sequence of input pairs that causes this method to produce a tree of height 4. */
/* Note : The amortized cost per operation for this algorithm is known to be bounded by a */ 
/* function known as the inverse Ackermann function and is less than 5 for any conceivable */ 
/* practical value of N. */


#include <vector>
#include <iostream>
#include <array>

class UF {
public:
  UF() = default;
  UF(int n);
public:
  void link(int p, int q);
  int count() const { return cnt; }
  bool connected(int p, int q) { return find(p) == find(q); }
  int find(int p);
private:
  std::vector<int> id; // site indexed array
  std::vector<int> sz; // size of component for roots (site indexed)
  int cnt;             // number of components
};

inline UF::UF(int n) {
  cnt = n;
  
  for (int i = 0; i < n; ++i) {
    id.push_back(i);
    sz.push_back(1);
  }
};

inline int UF::find(int site) {
  while (site != id[site]) {
    id[site] = id[id[site]];
    site = id[site];
  }
  return site;
};

inline void UF::link(int site1, int site2) {
  int root1 = find(site1);
  int root2 = find(site2);
  if (root1 == root2) { return; }
  
  auto newSize = sz[root1] + sz[root2];
  if (sz[root1] < sz[root2]) {
    id[root1] = root2;
    sz[root2] = newSize;
  } else {
    id[root2] = root1;
    sz[root1] = newSize;
  }
  
  --cnt;
};

int main() {
  UF uf(19);
  
  uf.link(0, 1);
  uf.link(0, 2);
  uf.link(0, 3);
  uf.link(6, 7);
  uf.link(8, 9);
  uf.link(6, 8);
  uf.link(0, 6);
  uf.link(10, 11);
  uf.link(10, 12);
  uf.link(10, 13);
  uf.link(10, 14);
  uf.link(10, 15);
  uf.link(10, 16);
  uf.link(10, 17);
  uf.link(10, 18);
  uf.link(0, 10);
  
  std::cout << "Components: " << uf.count() << " Expected: 3" << "\n";
  
  return 0;
}
