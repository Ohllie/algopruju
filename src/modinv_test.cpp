#include <cassert>
#include "modinv.hh"
#include "gcd.cpp"

int main() {
  for (int m = 1; m < 10000; ++m) {
    for (int a = 0; a < 2 * m; ++a) {
      if (gcd(a, m) % m == 1) {
        assert((a * modinv(a, m)) % m == 1);
      }
    }
  }

  return 0;
}
