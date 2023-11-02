// Prime Factors of N!::
map<int, int>mp;
while (prime[i] <= n) {
  int x = n, j = 1, ans = 0;
  while (x > 0) {
	ans += x / prime[i];
	x /= prime[i];
  }
  mp[prime[i]] = ans;
  i++;
}
