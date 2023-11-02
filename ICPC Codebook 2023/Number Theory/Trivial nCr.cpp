/* Used when there’s no mod used
* Time complexity: O(k)
* Step 1: ncr_triv<int>(n, r) */
template <typename T>
T ncr_triv (T n, T k) {
  T ncr = 1;
  if (n - k < k) {
    k = n - k;
  }
  for (T i = 0; i < k; ++i) {
    ncr *= (n - i);
    ncr /= (i + 1);
  }
  return ncr;
}
