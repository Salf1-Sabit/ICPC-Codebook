// Number of digit in n ::
const double eps = 1e-9;
int numberDigit ( int n ) {
  int rightAnswer = log10(n) + 1 + eps;
  return rightAnswer;
}
