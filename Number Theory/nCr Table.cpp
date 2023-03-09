long long ncr[maxn][maxn] = {0};
const int mod = (int) 1e9 + 7;
void init () {
  ncr[0][0] = 1;
  for (int i = 1; i < maxn; i++) {
    ncr[i][0] = 1;
    for (int j = 1; j < i + 1; j++) {
      ncr[i][j] = (ncr[i - 1][j - 1] + ncr[i - 1][j]) % mod;
    }
  }
}
