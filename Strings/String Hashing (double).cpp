#include <bits/stdc++.h>
using namespace std;

const int mod = (int) 1e9 + 7;
int add_mod (int a, int b) { 
  int res = (a + b) % mod;
  res += (res < 0 ? mod : 0);
  return res;
}

int sub_mod (int a, int b) { 
  int res = (a - b) % mod;
  res += (res < 0 ? mod : 0);
  return res;
}

int mult_mod (int a, int b) { 
  int res = (a * 1LL * b) % mod;
  res += (res < 0 ? mod : 0);
  return res;
}

template<typename T, typename X>
T binary_expo (T val, T power, X m) {
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

int main () {
  /* ios::sync_with_stdio(false); */
  /* cin.tie(0); */

  string s;
  cin >> s;

  /* This block of code completely double hashes the string S */
  int p1 = 31, p2 = 53;
  int n = (int) s.size();
  vector<int> pref_hash1(n);
  vector<int> pref_hash2(n);
  pref_hash1[0] = (s[0] - 'a') + 1;
  pref_hash2[0] = (s[0] - 'a') + 1;
  /* The inverse array is needed to substract the substring's hash */
  vector<int> p_pow1(n), inv1(n);
  vector<int> p_pow2(n), inv2(n);
  p_pow1[0] = inv1[0] = 1;
  p_pow2[0] = inv2[0] = 1;
  for (int i = 1; i < n; i++) { 
    p_pow1[i] = (p_pow1[i - 1] * 1LL * p1) % mod;
    p_pow2[i] = (p_pow2[i - 1] * 1LL * p2) % mod;
    inv1[i] = binary_expo<int>(p_pow1[i], mod - 2, mod);
    inv2[i] = binary_expo<int>(p_pow2[i], mod - 2, mod);
    pref_hash1[i] = add_mod(pref_hash1[i - 1], mult_mod((s[i] - 'a' + 1), p_pow1[i]));
    pref_hash2[i] = add_mod(pref_hash2[i - 1], mult_mod((s[i] - 'a' + 1), p_pow2[i]));
  }

  /* This function returns the hash-1 of the substring of string s
   * Moreover, this function also uses 0 based indesing */
  auto substring_hash1 = [&] (int l, int r) { 
    int res = pref_hash1[r];
    if (0 < l) { 
      res -= pref_hash1[l - 1];
    }
    res = mult_mod(res, inv1[l]);
    return res;
  };
  /* This function returns the hash-1 of the substring of string s
   * Moreover, this function also uses 0 based indesing */
  auto substring_hash2 = [&] (int l, int r) { 
    int res = pref_hash2[r];
    if (0 < l) { 
      res -= pref_hash2[l - 1];
    }
    res = mult_mod(res, inv2[l]);
    return res;
  };

  /* This block of code quering for each substring hash*/
  int q;
  cin >> q;
  while (q--) { 
    int l, r;
    cin >> l >> r;
    --l, --r;
    cout << substring_hash1(l, r) << '\n';
    cout << substring_hash2(l, r) << '\n';
  }
  return 0;
}
