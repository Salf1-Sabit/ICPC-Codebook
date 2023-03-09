/* Time complexity (construction): */ 
/*   * number of nodes. Which depends on matched prefix. */
/*   * the more prefix-match, the better. */
/* Time complexity (per query): */ 
/*   * length of the asked string */ 
/* Step 1: trie tri; */
/* Step 2: tri.insert(s); */
/* Step 3: cout << (tri.search(t) ? "YES\n" : "NO\n") << '\n'; */
/* Step 4: tri.del(); */
/* Note: useful for searching a string is present or not */
struct trie { 
  struct node { 
    bool endmark;
	/* Change the size to (10) if working with digits */
    node* next[26];
    node () { 
      endmark = false;
	  /* Change the limit to 10 if working with digits */
      for (int i = 0; i < 26; ++i) { 
        next[i] = NULL;
      }
    }
  } * root;
  /* trie tri; */
  trie () { 
    root = new node();
  }
  /* tri.insert(s); */
  /* inserts a string the the trie */
  void insert (string s) { 
    node* curr = root;
    for (auto ch : s) { 
      /* change 'a' according to the problem statement */
      int id = ch - 'a';
      if (curr -> next[id] == NULL) { 
        curr -> next[id] = new node();
      }
      curr = curr -> next[id];
    }
    curr -> endmark = true;
  }
  /* return if a string is present in the list or not */
  /* cout << (tri.search(t) ? "YES\n" : "NO\n") << '\n'; */
  bool search (string s) { 
    node* curr = root;
    for (auto ch : s) { 
      /* change 'a' according to the problem statement */
      int id = ch - 'a';
      if (curr -> next[id] == NULL) { 
        return false;
      }
      curr = curr -> next[id];
    }
    return curr -> endmark;
  }
  void del_node (node* curr) { 
	/* Change the limit to 10 if working with digits */
    for (int i = 0; i < 26; ++i) { 
      if (curr -> next[i]) { 
        del_node(curr -> next[i]);
      }
    }
    delete(curr);
  }
  /* tri.del(); */
  /* deletes, all the nodes. Useful in reducing memory */
  void del () { 
    del_node(root);
  }
};
