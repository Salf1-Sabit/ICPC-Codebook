/* This code finds the farthes nodes/leaves from each node 
   IDEA: 
     1. At first maintain 1st and 2nd farthest node from each node in it's own subtree, while climbing up the tree levels
       - denoted as (down[v].first | down[v].second)
     2. Then, find the farthest node outside of it's subtree, while climbing down the tree levels
       - denoted as (up[v])
     3. Then, farthest dist would be farthest_dist[v] = max(up[v], down[v].first) 
   Time complexity: Linear */

#include <bits/stdc++.h>
using namespace std;

const int N = (int) 2e5 + 1;
vector<int> parent(N);
vector<int> nei[N], depth_ver[N];

struct value { 
  int val = 0;
  int ver = 0;
};

void dfs (int u, int p = -1, int l = 0) { 
  parent[u] = p;
  depth_ver[l].push_back(u);
  for (auto v : nei[u]) { 
    if (p != v) { 
      dfs(v, u, l + 1);
    }
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k, c;
    cin >> n >> k >> c;
    for (int i = 0; i < n - 1; ++i) { 
      int u, v;
      cin >> u >> v;
      nei[u].push_back(v);
      nei[v].push_back(u);
    }
    dfs(1);
    vector<pair<value, value>> down(n + 1);
    for (int l = n - 1; 0 <= l; --l) { 
      for (auto u : depth_ver[l]) { 
        for (auto v : nei[u]) { 
          if (v != parent[u]) { 
            if (down[u].first.val < down[v].first.val + 1) { 
              down[u].first.val = down[v].first.val + 1;
              down[u].first.ver = v;
            }
          }
        }
        for (auto v : nei[u]) { 
          if (v != parent[u] and v != down[u].first.ver) { 
            if (down[u].second.val < down[v].first.val + 1) { 
              down[u].second.val = down[v].first.val + 1;
              down[u].second.ver = v;
            }
          }
        }
      }
    }
    vector<int> up(n + 1);
    for (int l = 1; l <= n - 1; ++l) { 
      for (auto u : depth_ver[l]) { 
        int p = parent[u];
        up[u] = up[p] + 1;
        if (down[p].first.ver == u) { 
          up[u] = max(up[u], down[p].second.val + 1);
        } else { 
          up[u] = max(up[u], down[p].first.val + 1);
        }
      }
    }
    vector<int> farthest_node_dist(n + 1); // This vector contains the farthest node/leaf dist
    for (int u = 1; u <= n; ++u) { 
      farthest_node_dist[u] = max(up[u], down[u].first.val);
      cout << "farthest_node[" << u << "] = " << farthest_node_dist[u] << '\n';
    }
    cout << "\n";
    for (int u = 1; u <= n; ++u) { 
      nei[u].clear();
      int level = u - 1;
      depth_ver[level].clear();
    }
  }
  return 0;
}
