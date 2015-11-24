int gcd(int a, int b) {
  while (a != 0) {
    int temp = a;
    a = b % a;
    b = temp;
  }
  return b;
}
