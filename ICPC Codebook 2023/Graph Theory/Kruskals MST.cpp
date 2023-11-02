/* Before this, make sure to write the dsu algo */
/* Time complexity: O(mlog(m)) - only for sorting, others done in constant time */
disjoint_set<int> dsu(n + 1);
auto kruskals = [&] () { 
  long long min_cost = 0;
  /* The edges must be sorted in asc according to their weights */
  sort(p.begin(), p.end());
  for (int i = 0; i < m; ++i) { 
    /* p[i][0] = cost, p[i][1] = u, p[i][2] = v; */
    if (dsu.find_set(p[i][1]) != dsu.find_set(p[i][2])) { 
      min_cost += p[i][0];
      dsu.make_set(p[i][1], p[i][2]);
    }
  }
  return min_cost;
};
