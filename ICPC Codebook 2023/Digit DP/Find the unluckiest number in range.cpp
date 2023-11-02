/*  Let's define the luckiness of a number x as the difference between the largest and smallest digits of that number. For example, 142857 has 8 as its largest digit and 1 as its smallest digit, so its luckiness is 8−1=7. And the number 111 has all digits equal to 1, so its luckiness is zero. 
    Now, you've to find the unluckiest number in the range (l, r) */

#include <bits/stdc++.h> 
using namespace std;

string str_a, str_b;
long long overall_ans;
short overall_min_dist = 9;
short dp[19][2][2][10][10]; // This is the time complexity as well

short sol (int pos = 0, bool bigger_a = false, bool smaller_b = false, short max_dig = 0, short min_dig = 9, long long new_seq = 0) { 
  if (pos == (int) str_b.size()) { 
    if (max_dig - min_dig <= overall_min_dist) { 
      overall_min_dist = max_dig - min_dig;
      overall_ans = new_seq;
    }
    return max_dig - min_dig;
  }
  short& tmp_dist = dp[pos][bigger_a][smaller_b][max_dig][min_dig];
  if (tmp_dist != -1) { 
    return tmp_dist;
  }
  tmp_dist = 9;
  short left_cand = bigger_a ? 0 : str_a[pos] - '0';
  short right_cand = smaller_b ? 9 : str_b[pos] - '0';
  for (short tmp_dig = left_cand; tmp_dig <= right_cand; ++tmp_dig) { 
    tmp_dist = min(tmp_dist, sol(pos + 1, bigger_a | str_a[pos] - '0' < tmp_dig, smaller_b | tmp_dig < str_b[pos] - '0', max(max_dig, tmp_dig), min(min_dig, tmp_dig), new_seq * 10 + tmp_dig));
  }
  return tmp_dist;
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) { 
    long long a, b;
    cin >> a >> b;
    str_a = to_string(a);
    str_b = to_string(b);
    if ((int) str_a.size() < (int) str_b.size()) { 
      cout << string((int) str_a.size(), '9') << '\n';
      continue;
    }
    overall_min_dist = 9;
    memset(dp, -1, sizeof dp);
    sol();
    cout << overall_ans << '\n';
  }
  return 0;
}

