template <typename T>
bool fermat (T n, int iter=5) {
  if (n < 4) { 
    return n == 2 or n == 3;
  }
  for (int i = 0; i < iter; i++) {
    T a = 2 + rand() % (n - 3);
    if (binary_expo<T>(a, n - 1, n) != 1) { 
      return false;
    }
  }
  return true;
}
