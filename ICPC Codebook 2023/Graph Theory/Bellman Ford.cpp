/* Time complexity: O(V * E) */
/* Add edges both ways for undirected graph */
/* g.push_back({u, v, w}); */
/* g.push_back({v, u, w}); */
int cyc_node = -1;
const int inf = (int) 1e9;
vector<int> dist(n + 1, inf);
vector<int> par(n + 1, -1);
auto check_neg_cycle = [&] () { 
  if (cyc_node == -1) { 
    return printf("No neg cycle\n"), 0;
  }
  int u = cyc_node;
  for (int i = 1; i <= n; ++i) { 
    u = par[u];
  }
  vector<int> path;
  for (int cur = u; ; cur = par[cur]) { 
    path.push_back(cur);
    if (1 < (int) path.size() and cur == u) { 
	  break;
    }
  }
  reverse(path.begin(), path.end());
  for (auto p : path) { 
    printf("%d ", p);
  }
  printf("\n");
  return 0;
};
auto bellman_ford = [&] (int src) { 
  dist[src] = 0;
  for (int i = 1; i <= n; ++i) { 
    cyc_node = -1;
    for (int j = 0; j < m; ++j) { 
	  int u = g[j][0];
	  int v = g[j][1];
	  int w = g[j][2];
	  if (dist[u] < inf) { 
	    if (dist[u] + w < dist[v]) { 
		  dist[v] = max(-inf, dist[u] + w);
		  par[v] = u;
		  cyc_node = v;
	    }
	  }
    }
  }
  check_neg_cycle();
};
bellman_ford(1);
