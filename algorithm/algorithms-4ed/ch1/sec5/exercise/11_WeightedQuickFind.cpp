/* 1.5.11 Implement weighted quick-find, where you always change the id[] entries of */
/* the smaller component to the identifier of the larger component. How does this change */
/* affect performance? */

/* The change in WeightedQuickFind will slightly improve performance.  Find() will */
/* still be O(1) and union() operation will still be O(n), but there will be less */
/* parent updates in the union operation (at most n / 2). */

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

inline void QuickUnionUF::connect(int p, int q) {
  auto root1 = find(p);
  auto root2 = find(q);
  
  if (root1 == root2) { return; }

  int rootToUpdate;
  int newRootId;

  if (sz[p] < sz[q]) {
    rootToUpdate = root1;
    newRootId = root2;
  }
  else {
    rootToUpdate = root2;
    newRootId = root1;
  }

  for (int i = 0; i < id.size(); ++i) {
    if (id[i] == rootToUpdate) {
      id[i] = newRootId;
    }
  }
};
