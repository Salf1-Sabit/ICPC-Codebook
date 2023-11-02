// Space Optimized LCS 
// Space - O(N) | Time - (N * M)

#include <bits/stdc++.h>
using namespace std;

int main() {
  string s = "AGGTAB";
  string t = "GXTXAYB"; // Ans = 4
  int n = (int) s.size();
  int m = (int) t.size();
  vector<vector<int>> dp(2, vector<int>(m + 1));
  for (int i = 0; i <= n; ++i) { 
    int k = i & 1;
    for (int j = 0; j <= m; ++j) { 
      if (i == 0 or j == 0) { 
        dp[k][j] = 0;
      } else if (s[i - 1] == t[j - 1]) { 
        dp[k][j] = 1 + dp[k ^ 1][j - 1];
      } else { 
        dp[k][j] = max(dp[k ^ 1][j], dp[k][j - 1]);
      }
    }
  }
  cout << max(dp[1][m], dp[0][m]) << '\n';
  return 0;
}
