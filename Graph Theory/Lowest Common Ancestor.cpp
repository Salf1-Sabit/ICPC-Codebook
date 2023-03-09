/* Time complexity: Build O(nlog(n)), Query O(log(n)); */
/* Step 1: binary_lifting bl(n, m, g); */
/* Step 2: bl.lca(u, v); */
/* Step 3: bl.get_dist(u, v); */
struct binary_lifting { 
  int n, m;
  vector<int> lvl;
  vector<vector<int>> g;
  vector<vector<int>> par;
  void dfs (int v, int l, int p) { 
    lvl[v] = l;
    par[v][0] = p;
    for (auto ch : g[v]) { 
      if (ch != p) { 
        dfs(ch, l + 1, v);
      }
    }
  }
  void init () { 
    dfs(1, 0, -1);
    const int logn = __lg(n);
    for (int i = 1; i <= logn; ++i) { 
      for (int j = 1; j <= n; ++j) { 
        if (par[j][i - 1] != -1) { 
          int p = par[j][i - 1];
          par[j][i] = par[p][i - 1];
        }
      }
    }
  }
  // builds the structure
  binary_lifting (int n, int m, vector<vector<int>> g) {
    this -> n = n;
    this -> m = m;
    this -> g = g;
    lvl.assign(n + 1, 0);  
    const int logn = __lg(n);
    par.assign(n + 1, vector<int>(logn + 1, -1));
    init();
  }
  // Returns the lowest common ancestor of two nodes
  int lca (int u, int v) { 
    if (lvl[v] < lvl[u]) { 
      swap(v, u);
    }
    int d = lvl[v] - lvl[u];
    while (d) { 
      int logd = __lg(d);
      v = par[v][logd];
      d -= (1 << logd);
    }
    if (u == v) { 
      return u;
    }
    int logn = __lg(n);
    for (int i = logn; i >= 0; --i) { 
      if (par[u][i] != -1 and par[u][i] != par[v][i]) { 
        u = par[u][i];
        v = par[v][i];
      }
    }
    return par[u][0];
  }
  // Returns the distance between two nodes
  int get_dist (int u, int v) { 
    int com_ances = lca(u, v);
    return lvl[u] + lvl[v] - (lvl[com_ances] << 1);
  }
};
