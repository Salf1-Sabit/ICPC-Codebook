// Number of trailing Zeros in N! ::
ll zeros = 0;
for (ll i = 5; i <= n; i *= 5) {
  zeros += (n / i);
}
