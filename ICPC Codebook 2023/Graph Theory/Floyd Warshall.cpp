/* Time complexity: O(n ^ 3) */
auto floyd_warshall = [&] () { 
  /* init the (d) array, if there doesn't exists a path b/w u-v then set them to infinity */ 
  const int inf = (int) 1e9;
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) { 
      for (int j = 1; j <= n; ++j) { 
       /* if there exists both of these path or not */
        if (d[i][k] < inf and d[k][j] < inf) { 
          d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
      }
    }
  }
};
