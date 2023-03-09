/** 1. struct lazy_propagation <int64_t>lazy_prop(a);
  * 2. lazy_prop.build(1, 0, n - 1);
  * 3. now, you're good to go.
 **/
template <typename T>
struct lazy_propagation {
  struct info {
    T sum = 0, prop = 0;
  };
  int n;
  vector<T> a;
  vector<info> tree;
  lazy_propagation (vector<T> cpy) { 
    a = cpy;
    n = (int) a.size();
    tree.resize(4 * n);
  };
  void build (int node, int l, int r) {
    if (l == r) { 
      tree[node].sum = a[l];
      return;
    }
    int mid = (l + r) >> 1;
    build(node << 1, l, mid);
    build((node << 1) + 1, mid + 1, r);
    tree[node].sum = tree[node << 1].sum + tree[(node << 1) + 1].sum;
  }
  T sum (int node, int start, int end, int l, int r, T carry = 0) { 
    if (end < l or r < start) {
      return 0;
    }
    if (l <= start and end <= r) { 
      return tree[node].sum + (((end - start) + 1) * carry);
    }
    int mid = (start + end) >> 1;
    T left_sum = sum(node << 1, start, mid, l, r, carry + tree[node].prop);
    T right_sum = sum((node << 1) + 1, mid + 1, end, l, r, carry + tree[node].prop);
    return left_sum + right_sum;
  }
  void update (int node, int start, int end, int l, int r, T val) { 
    if (end < l or r < start) {
      return;
    }
    if (l <= start and end <= r) {
      tree[node].sum += ((end - start) + 1) * val;
      tree[node].prop += val;
      return;
    }
    int mid = (start + end) >> 1;
    update(node << 1, start, mid, l, r, val);
    update((node << 1) + 1, mid + 1, end, l, r, val);
    tree[node].sum = tree[node << 1].sum + tree[(node << 1) + 1].sum + (((end - start) + 1) * tree[node].prop);
  }
};
