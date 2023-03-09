/* Time complexity: O(N) */
/* While solving this problem always try to solve this on the basis of the generated answer it is returning */
/* Which means, always try to solve on the basis of converted string -> #a#b#a# */
/* Return the length of a palindrome from left side, defining (i) as the middle of that palindrome*/
/* manachers<int> man(s); */
/* auto ans = man.ret_ans(); */
template <typename T> 
struct manachers { 
  int n;
  vector<int> p;
  void manac_odd (string s) { 
    n = (int) s.size();
    s = "(" + s + ")";
    p.assign(n + 2, 0);
    int l = 1, r = 1;
    for (int i = 1; i <= n; ++i) { 
      p[i] = max(0, min(r - i, p[l + (r - i)]));
      while (s[i - p[i]] == s[i + p[i]]) { 
        p[i] += 1;
      }
      if (r < i + p[i]) { 
        l = i - p[i];
        r = i + p[i];
      }
    }
  }
  manachers (string t) { 
    string s = "";
    for (auto c : t) { 
      s += string("#") + c;
    }
    manac_odd(s + "#");
  }
  vector<T> ret_ans () { 
    return vector<T>(p.begin() + 1, p.end() - 1);
  }
};
