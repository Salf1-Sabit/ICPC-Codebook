// Count all subsets having K set bits after bitwise AND

#include <bits/stdc++.h>
using namespace std;

const int maxn = (int) 2e5;
const int mod = (int) 1e9 + 7;
const int all_subset = 1 << 6;
typedef vector<int> custom;

int add_mod (int a, int b) { 
  int res = (a + b) % mod;
  res += (res < 0 ? mod : 0);
  return res;
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int tt;
  cin >> tt;
  while (tt--) { 
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) { 
      cin >> a[i];
    }
    vector<custom> dp(n + 1, custom(all_subset));
    for (int i = 0; i < n; ++i) { 
      dp[i + 1][a[i]] = add_mod(dp[i + 1][a[i]], 1); // Start a subsequence from the (ith) element
      for (int mask = 0; mask < all_subset; ++mask) { 
        dp[i + 1][mask] = add_mod(dp[i + 1][mask], dp[i][mask]); // Don't take the (ith) element into the current subsequence
        dp[i + 1][mask & a[i]] = add_mod(dp[i + 1][mask & a[i]], dp[i][mask]); // Take the (ith) element into the current subsequence
      }
    }
    long long ans = 0;
    for (int mask = 0; mask < all_subset; ++mask) { 
      if (__builtin_popcount(mask) == k) { 
        ans = add_mod(ans, dp[n][mask]);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
