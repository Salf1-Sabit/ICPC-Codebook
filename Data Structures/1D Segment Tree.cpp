/** 1. segment_tree<long long> seg_tree(a);
  * 2. seg_tree.build(1, 0, n - 1);
  * 3. Note : Make sure that the segment tree type and the 
       vector type must mathc. E.g If, struct segment_tree <long long> 
	   then, vector must be vector<long long>
  *	4. Note : While using index for answer. Make sure to use them as (0 based)
  * 5. now, you're good to go.
 **/
template <typename T>
struct segment_tree {
  int n;
  vector<T> a, tree;
  /* Used to create the tree array */
  segment_tree (vector<T> cpy) { 
    a = cpy;
    n = (int) a.size();
    tree.assign(n << 2, 0);
  };
  /* used to build the tree */ 
  void build (int node, int l, int r) {
    if (l == r) { 
      tree[node] = a[l];
      return;
    }
    int mid = (l + r) >> 1;
    build(node << 1, l, mid);
    build((node << 1) + 1, mid + 1, r);
    tree[node] = tree[node << 1] + tree[(node << 1) + 1];
  }
  /* point sum or range sum */ 
  T sum (int node, int start, int end, int l, int r) { 
    if (end < l or r < start) {
      return 0;
    }
    if (l <= start and end <= r) { 
      return tree[node];
    }
    int mid = (start + end) >> 1;
    T left_sum = sum(node << 1, start, mid, l, r);
    T right_sum = sum((node << 1) + 1, mid + 1, end, l, r);
    return left_sum + right_sum;
  }
  /* point updating value / adding value */
  void update (int node, int start, int end, int id, T val) { 
    if (start == end) {
      tree[node] = val;
      return;
    }
    int mid = (start + end) >> 1;
    if (id <= mid) { 
      update(node << 1, start, mid, id, val);
    } else {
      update((node << 1) + 1, mid + 1, end, id, val);
    }
    tree[node] = tree[node << 1] + tree[(node << 1) + 1];
  }
};
