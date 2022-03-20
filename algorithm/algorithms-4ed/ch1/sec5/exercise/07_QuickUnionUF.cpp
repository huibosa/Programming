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
  int find(int p) const;
  void connect(int p, int q);
  bool isConnected(int p, int q) const { return find(p) == find(q); }
  int count() const { return cnt; }
private:
  std::vector<int> id;
  std::vector<int> sz;
  int cnt;
};

inline QuickUnionUF::QuickUnionUF(int n) {
  cnt = n;
  for (int i = 0; i < n; ++i) {
    id.push_back(i);
    sz.push_back(1);
  }
};

inline int QuickUnionUF::find(int p) const {
  while (p != id[p]) {
    p = id[p];
  }
  return p;
};

inline void QuickUnionUF::connect(int p, int q) {
  auto i = find(p);
  auto j = find(q);
  
  if (i == j) { return; }

  id[i] = j;

  --cnt;
};
