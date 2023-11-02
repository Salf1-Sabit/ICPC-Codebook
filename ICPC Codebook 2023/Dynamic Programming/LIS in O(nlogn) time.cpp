// LIS in O(nlog(n))
int LIS (vector<int> const& a) {
  int n = a.size();
  const int inf = 1e9;
  vector<int> dp(n + 1, inf);
  dp[0] = -inf;
  for (int i = 0; i < n; i++) {
    int l = upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
    if (dp[l - 1] < a[i] and a[i] < dp[l]) { 
      dp[l] = a[i];
    }
  }
  int ans = 0;
  for (int l = 0; l <= n; l++) {
    if (dp[l] < inf) { 
      ans = l;
    }
  }
  return ans;
}
