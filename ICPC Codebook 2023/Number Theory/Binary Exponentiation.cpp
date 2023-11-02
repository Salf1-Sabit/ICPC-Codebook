/* binary_expo<int>(2, n - 1, m); */
template<typename T, typename X>
T binary_expo (T val, T power, X m) {
  T output = 1;
  while (power) {
    if (power & 1) {
      output = T((output * 1LL * val) % m);
    }
    val = (val * 1LL * val) % m;
    power >>= 1;
  }
  return output;
}
