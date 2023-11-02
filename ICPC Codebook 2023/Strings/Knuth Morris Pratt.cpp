/* Total complexity: O(n + m) */
/* Application (string problems) : */ 
/*  1. Used to extract matched positions */
/*  2. Used to know if we have a match or not */
/* kmp<int> km(full_string, pattern_to_search_for); */
/* auto ids = km.pos(); */
template <typename T> 
struct kmp {
  int n, m;
  string s, t;
  vector<T> tab;
  // Creating the prefix length table
  void proc () { 
    int i = 0;
    for (int j = 1; j < m;) { 
      if (t[i] == t[j]) { 
        tab[j] = i + 1;
        i += 1, j += 1;
      } else { 
        if (i) { 
          i = tab[i - 1];
        } else { 
          j += 1;
        }
      }
    }
  }
  // initializing everything
  kmp (string s, string t) {
    this -> s = s;
    this -> t = t;
    n = (T) s.size();
    m = (T) t.size();
    tab.assign(m, 0);
    proc();
  }
  // Returns all the starting positions where we have a match
  // If we have a match we continue, 
  // Otherwise, we look in the previous index of the table to save time.
  vector<T> pos () { 
    int i = 0;
    int j = 0;
    vector<T> ids;
    while (i < n) { 
      if (s[i] == t[j]) { 
        i += 1, j += 1;
      } else { 
        if (j) { 
          j = tab[j - 1];
        } else { 
          i += 1;
        }
      }
      // If pattern found take the index
      if (j == m) { 
        ids.push_back(i - m);
        j = tab[j - 1];
      }
    }
    return ids;
  }
};
