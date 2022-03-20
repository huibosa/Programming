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

inline int UF::find(int p) const {
  while (p != id[p]) {
    p = id[p];
  }
  return p;
};

inline void UF::link(int p, int q) {
  int i = find(p);
  int j = find(q);
  if (i == j) { return; }
  
  if (sz[i] < sz[j]) {
    id[i] = j;
    sz[j] += sz[i];
  } else {
    id[j] = i;
    sz[i] += sz[j];
  }
  
  --cnt;
};

int main() {
  int n;
  std::cin >> n;
  auto uf = new UF(n);

  for (auto p = 0, q = 0; std::cin >> p, std::cin >> q;) {
    if (uf->connected(p, q)) { continue; }

    uf->link(p, q);
    std::cout << p << " " << q << "\n";
  }
  std::cout << uf->count() << " components" << "\n";

  return 0;
}
