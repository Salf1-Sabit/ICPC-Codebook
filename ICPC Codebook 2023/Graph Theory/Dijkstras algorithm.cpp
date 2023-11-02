/* Used to extract the shortest path from source(u) to destination(v) */
/* Time complexity: O(V + E log V) */
/* dijkstra<int> dij(g, n, --src); */
/* dij.proc_tab(); */
/* cout << dij.get_dist(--v) << '\n'; */
/* auto path = dij.get_path(v); */
/* Follows 0-based indexing */
template <typename T> 
struct dijkstra { 
  int n;
  int src;
  // Change this (inf) according to the question
  const T inf = (T) 1e16;
  vector<int> par, seen;
  vector<T> dist;
  vector<vector<array<int, 2>>> g;
  dijkstra (vector<vector<array<int, 2>>> g, int n, int src) { 
    this -> g = g;
    this -> n = n;
    this -> src = src;
    // Remove this (par) if not needed
    par.assign(n, -1);
    seen.assign(n, false);
    dist.assign(n, inf);
  }
  void proc_tab () { 
    multiset<array<T, 2>> ms;
    dist[src] = 0;
    ms.insert({0, src});
    while (!ms.empty()) { 
      auto u = *ms.begin();
      ms.erase(ms.begin());
      if (!seen[u[1]]) { 
        seen[u[1]] = true;
        for (auto ch : g[u[1]]) { 
          if (dist[u[1]] + ch[1] < dist[ch[0]]) { 
            dist[ch[0]] = dist[u[1]] + ch[1];
            /* Here saving the previous node as parent if this is giving less cost */
            par[ch[0]] = u[1];
            ms.insert({dist[ch[0]], ch[0]});
          }
        }
      }
    }
  }
  T get_dist (int dest) { 
    return dist[dest];
  }
  vector<int> get_path (int dest) { 
    vector<int> path;
    for (int v = dest; v != -1; v = par[v]) { 
      path.push_back(v + 1);
    }
    reverse(path.begin(), path.end());
    return path;
  }
};
