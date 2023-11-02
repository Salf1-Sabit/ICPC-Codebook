/* disjoint_set<int> dsu(n + 1); */
/* dsu.make_set(u, v); */
vector<int> par, siz;
template<typename T>
struct disjoint_set { 
  int n;
  T find_set(T v) {
    if (par[v] == v) {
      return v;
    }
    return par[v] = find_set(par[v]);
  }
  void init(T v) {
    par[v] = v;
    siz[v] = 1;
  }
  disjoint_set (int n) { 
    this -> n = n;
    siz.assign(n + 1, 0);
    par.assign(n + 1, 0);
    for (int u = 1; u <= n; ++u) {
      init(u);
    }
  }
  void make_set(T a, T b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
      if (siz[a] < siz[b]) {
        swap(a, b);
      }
      par[b] = a;
      siz[a] += siz[b];
    }
  }
  T find_group_size(T a) { 
    a = find_set(a);
    return siz[a];
  }
};
