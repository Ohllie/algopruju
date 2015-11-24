int mod_exp(int base, int exponent, int mod) {

  int result = 1;
  int d = base;
  while (exponent != 0) {
    if (exponent & 1u)
      result = (result * d) % mod;
    exponent >>= 1;
    d = (d * d) % mod;
  }
  return result;
}
