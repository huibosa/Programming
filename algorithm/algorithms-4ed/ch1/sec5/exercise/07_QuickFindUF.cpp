// Develop classes QuickUnionUF and QuickFindUF that implement quick-union and
// quick-find, respectively

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

class QuickUnionUF {
public:
  QuickUnionUF(int n);
public:
  int find(int p) const { return id[p]; }
  void connect(int p, int q);
  bool isConnected(int p, int q) const { return find(p) == find(q); }
  int count() const { return cnt; }
private:
  std::vector<int> id;
  int cnt;
};

inline QuickUnionUF::QuickUnionUF(int n) {
  cnt = n;
  for (int i = 0; i < n; ++i) {
    id.push_back(i);
  }
};

inline void QuickUnionUF::connect(int p, int q) {
  auto pRoot = find(p);
  auto qRoot = find(q);
  
  if (pRoot == qRoot) { return; }

  for (int i = 0; i < id.size(); ++i) {
    if (id[i] == pRoot) {
      id[i] = qRoot;
    }
  }
};
