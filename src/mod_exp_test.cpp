#include <iostream>
#include <cassert>
#include "mod_exp.hh"

int mod_exp_naive(int base, int exponent, int mod) {
  int result = 1;
  for (int i = 0; i < exponent; i++) {
    result = (result * base) % mod;
  }
  return result;
}

int main() {
  for (int i = 0; i <= 100; i++) {
    assert(mod_exp(2, i, 101) == mod_exp_naive(2, i, 101));
    assert(mod_exp(i, i, 101) == mod_exp_naive(i, i, 101));
  }
  assert(mod_exp(3, 32982391, 101) == mod_exp_naive(3, 32982391, 
101));
  std::cout << "All tests OK" << std::endl;
}
