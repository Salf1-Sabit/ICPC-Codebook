// first k digit of N!
// sometime give error in k’th digit.
ll leadingDigitFact ( ll n, ll k ) {
  long double fact = 0;
  for ( ll i = 1; i <= n; i++ ) {
    fact += log10 ( i );
  }
  long double q = fact - floor ( fact + eps );
  long double B = pow ( 10, q );
  for ( ll i = 0; i < k - 1; i++ ) {
    B *= 10LL;
  }
  return floor(B + eps);
}
