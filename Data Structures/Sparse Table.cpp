/* Used for answering queries, but can answer R(Min/Max)Q in O(1) */
/* Step 1: sparse_table<int> st(a, N); */
/* Step 2: cout << st.min_query(l, r) << '\n'; */
template <typename T> 
struct sparse_table { 
  int N;
  int n, k;
  vector<T> a;
  vector<T> logs;
  vector<vector<T>> st;
  void gen_logs () { 
    logs[1] = 0;
    for (int i = 2; i <= N; i++) { 
      logs[i] = logs[i/2] + 1;
    }
  }
  // builds the table
  void proc () { 
    st[0] = a;
    for (int i = 1; i <= k; ++i) { 
      for (int j = 0; j + (1 << i) - 1 < n; ++j) {
        /* Change this line according the question */
        st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
      }
    }
  }
  // builds the structure
  sparse_table (vector<T> a, int N) { 
    this -> a = a;
    this -> N = N;
    n = (int) a.size();
    logs.assign(N + 1, 0);
    gen_logs();
    k = logs[n];
    st.assign(k + 1, vector<T>(n + 1, 0));
    proc();
  }
  /* This function is used for only min/max query O(1); */
  T min_query (int l, int r) { 
    int p = logs[r - l + 1];
    return min(st[p][l], st[p][r - (1 << p) + 1]);
  }
  /* This function is used for the rest of the queries - in O(log(n)) */
  T sum_query (int l, int r) { 
    T sum = 0;
    for (int i = k; i >= 0; --i) { 
      if ((1 << i) <= r - l + 1) { 
        sum += st[i][l];
        l += 1 << i;
      }
    }
    return sum;
  }
};
