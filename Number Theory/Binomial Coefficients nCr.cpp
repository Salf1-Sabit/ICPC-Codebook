/* Time complexity: log(MOD - 2) */
/* Step 1: bin_coeff<int> bcoef(MAXN, MOD); */
/* Step 2: bcoef.nCr(n, r); */
template <typename T>
struct bin_coeff { 
  T n, m;
  vector<T> fact;
  void gen_fact () { 
    fact[0] = fact[1] = 1;
    for (int i = 2; i <= n; ++i) { 
      fact[i] = (1LL * fact[i - 1] * i) % m;
    }
  }
  bin_coeff (T n, T m) { 
    this -> n = n;
    this -> m = m;
    fact.resize(n + 1);
    gen_fact();
  }
  T inv (T val, T power) {
    T output = 1;
    while (power) {
      if (power & 1) {
        output = T((output * 1LL * val) % m);
      }
      val = (val * 1LL * val) % m;
      power >>= 1;
    }
    return output;
  }
  T nCr (T N, T R) { 
    return (fact[N] * 1LL * inv((fact[R] * 1LL * fact[N - R]) % m, m - 2)) % m;
  }
};
