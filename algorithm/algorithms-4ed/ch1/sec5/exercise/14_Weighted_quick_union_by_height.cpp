/* 1.5.14   Weighted quick-union by height. Develop a UF implementation that uses the */ 
/* same basic strategy as weighted quick-union but keeps track of tree height and always */ 
/* links the shorter tree to the taller one. Prove a logarithmic upper bound on the height */ 
/* of the trees for N sites with your algorithm. */

// Also known as union by rank.
// The height of a tree will only increase when uniting with a tree of the same height,
// otherwise the smaller tree will join the biggest tree.
// This guarantees a logarithmic upper bound on the height of the trees for N sites.
// The size of a tree will be at most 2^height. Therefore, the height can increase at most lg N times.

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
  bool connected(int p, int q) const { return find(p) == find(q); }
  int find(int p) const;
  int maxHeight() const { return height; }
private:
  std::vector<int> id; // site indexed array
  std::vector<int> ht; // size of component for roots (site indexed)
  int cnt;             // number of components
  int height;
};

inline UF::UF(int n) {
  cnt = n;
  
  for (int i = 0; i < n; ++i) {
    id.push_back(i);
    ht.push_back(0);
  }
};

inline int UF::find(int p) const {
  while (p != id[p]) {
    p = id[p];
  }
  return p;
};

inline void UF::link(int site1, int site2) {
  int root1 = find(site1);
  int root2 = find(site2);
  if (root1 == root2) { return; }
  
  if (ht[root1] < ht[root2]) {
    id[root1] = root2;
  } else if (ht[root1] > ht[root2]) {
    id[root2] = root1;
  } else {
    id[root2] = root1;
    ++ht[root1];

    if (ht[root1] > this->height) {
      height = ht[root1];
    }
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
  std::cout << "Maxium height: " << uf.maxHeight()
            << " Expected: Equal or less than 5 for N = 19"
            << " (lg 19 = 5)"
            << "\n";
}
