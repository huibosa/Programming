#include <vector>
#include <iostream>

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
  std::vector<int> id;  // site indexed array
  int cnt;              // number of components
};

inline UF::UF(int n) {
  cnt = n;
  for (int i = 0; i < n; ++i) {
    id.push_back(i);
  }
};

inline int UF::find(int p) const {
  while (id[p] != p) {
    p = id[p];
  }
  return p;
};

// O(n^2)
inline void UF::link(int p, int q) {
  int pRoot = find(p);
  int qRoot = find(q);

  if (pRoot == qRoot) { return; }
  
  id[pRoot] = qRoot;

  cnt--;
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
