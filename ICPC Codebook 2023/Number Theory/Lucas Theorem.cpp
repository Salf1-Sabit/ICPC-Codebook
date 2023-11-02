// Lucas's Theorem calculates nCr % p in log(n). And if p < n and if p is not prime, multiple of two prime (mod = prime*prime)


// mint data-type is a custom data type which does mod own it's own.
// So, wherever "mint" has been used, we just need to use manual mod for the calculations when using it's values

#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 3, mod = 1e6 + 3;
using ll = long long;

struct combi{
  int n; vector<mint> facts, finvs, invs;
  combi(int _n): n(_n), facts(_n), finvs(_n), invs(_n){
    facts[0] = finvs[0] = 1;
    invs[1] = 1;
    for (int i = 2; i < n; i++) invs[i] =  invs[mod % i] * (-mod / i);
    for(int i = 1; i < n; i++){
      facts[i] = facts[i - 1] * i;
      finvs[i] = finvs[i - 1] * invs[i];
    }
  }
  inline mint fact(int n) { return facts[n]; }
  inline mint finv(int n) { return finvs[n]; }
  inline mint inv(int n) { return invs[n]; }
  inline mint ncr(int n, int k) { return n < k or k < 0 ? 0 : facts[n] * finvs[k] * finvs[n-k]; }
};

combi C(N);

// returns nCr modulo mod where mod is a prime
// Complexity: log(n)
mint lucas(ll n, ll r) {
  if (r > n) return 0;
  if (n < mod) return C.ncr(n, r);
  return lucas(n / mod, r / mod) * lucas(n % mod, r % mod);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << lucas(100000000, 2322) << '\n';
  return 0;
}
