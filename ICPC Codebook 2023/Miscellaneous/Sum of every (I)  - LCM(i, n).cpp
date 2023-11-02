// Ans = lcm(1,n) + lcm(2,n) + lcm(3,n) + lcm(4,n) + …. + lcm(n,n).
ll phi[N],r[N];
ll totalLcm(ll n){
  ll ans = 0;
  for (int i = 1; i < mx; i++) {
    for (int j = i; j < mx; j += i) {
      r[j] += phi[i] * i;
    }
  }
  ans = r[n] + 1;
  ans *= n;
  ans /= 2;
  return ans;
}
