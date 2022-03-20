/* 1.5.12     Quick-union with path compression. Modify quick-union (page 224) to include */ 
/* path compression, by adding a loop to union() that links every site on the paths from */ 
/* p and q to the roots of their trees to the root of the new tree. Give a sequence of input */ 
/* pairs that causes this method to produce a path of length 4. Note : The  amortized cost */ 
/* per operation for this algorithm is known to be logarithmic. */

#include <vector>
#include <iostream>

class UF {
public:
  UF() = default;
  UF(int n);
public:
  void link(int site1, int site2);
  int count() const { return cnt; }
  bool connected(int site1, int site2) { return find(site1) == find(site2); }
  int find(int site);
private:
  std::vector<int> id;  // site indexed array
  int cnt;              // number of components
};

inline UF::UF(int n) {
  cnt = n;
  for (int i = 0; i < n; ++i) {
    id.push_back(i);
  }
};

// amotized O(lg n)
inline int UF::find(int site) {
  auto root = site;
  while (id[root] != root) {
    root = id[root];
  }

  while (site != id[site]) {
    auto next = id[site];
    id[site] = root;
    site = next;
  }
  
  return root;
};

// amotized O(lg n)
inline void UF::link(int site1, int site2) {
  int root1 = find(site1);
  int root2 = find(site2);

  if (root1 == root2) { return; }
  
  while (id[site1] != root1) {
    auto next = id[site1];
    id[site1] = root2;
    site1 = next;
  }
  
  id[root1] = root2;

  cnt--;
};

int main() {
  UF uf1(10);
  
  uf1.link(0, 1);
  uf1.link(2, 3);
  uf1.link(3, 4);
  uf1.link(2, 4);

  std::cout << "Components: " << uf1.count() << " Expected: 7" << "\n";

  UF uf2(10);
  uf2.link(0, 1);
  uf2.link(2, 3);
  uf2.link(4, 5);
  uf2.link(6, 7);
  uf2.link(6, 4);
  uf2.link(4, 2);
  uf2.link(4, 0);

  std::cout << "Components: " << uf2.count() << " Expected: 3" << "\n";
}
