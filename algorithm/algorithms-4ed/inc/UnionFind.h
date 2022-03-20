#pragma once

#include <vector>

class UnionFind {
public:
  UnionFind(int n);
public:
  int findRoot(int site);
  void connect(int site1, int site2);
  bool isConnected(int site1, int site2) { return findRoot(site1) == findRoot(site2); }
  int count() const { return cnt; }
private:
  std::vector<int> id;
  std::vector<int> rank;
  int cnt;
};

inline UnionFind::UnionFind(int n) {
  for (int i = 0; i < n; ++i) {
    id.push_back(i);
    rank.push_back(1);
  }
  cnt = n;
};

inline int UnionFind::findRoot(int site) {
  while (site != id[site]) {
    id[site] = id[id[site]];
    site = id[site];
  }
  return site;
};

inline void UnionFind::connect(int site1, int site2) {
  auto root1 = findRoot(site1);
  auto root2 = findRoot(site2);

  if (root1 == root2) { return; }
  
  --cnt;

  auto newRank = rank[root1] + rank[root2];
  if (rank[root1] < rank[root2]) {
    id[root1] = root2;
    rank[root2] = newRank;
  } else {
    id[root2] = root1;
    rank[root1] = newRank;
  }
};

