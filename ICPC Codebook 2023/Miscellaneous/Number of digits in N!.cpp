Number of digit in N! ::
int factorialDigit ( int n ) {
  double x = 0;
  for ( int i = 1; i <= n; i++ ) {
    x += log10 ( i );
  }
  int res = x + 1 + eps;
  return res;
}
