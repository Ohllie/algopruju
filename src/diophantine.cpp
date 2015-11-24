#include <iostream>
#include <random>

using namespace std;

typedef int64_t Z;

/*
 * Given
 *   a, b, c >= 0
 *   b >= a, b > 0
 * calculates a solution (x,y) to the equation
 *   a*x + b*y = c
 * with 0 <= x < b/gcd(a,b).
 *
 * Returns gcd(a,b) if solution exists, and -gcd(a,b) otherwise.
 */

Z gcd_primitive(Z a, Z b, Z c, Z &x, Z &y) {
  if (a == 0) {
    x = 0;
    y = c / b;
    if (c % b == 0)
      return b;
    else
      return -b;
  }

  Z d = gcd_primitive(b % a, a, c, y, x);
  if (d < 0)
    return d;

  x -= (b / a) * y;

  if (x < 0) {
    x += b / d;
    y -= a / d;
  } else if (x > 0) {
    Z t = (-x) / (b / d);
    x += t * (b / d);
    y -= t * (a / d);
  }
  return d;
}

Z gcd(Z a, Z b, Z c, Z &x, Z &y) {
  if (c < 0) {
    return gcd(-a, -b, -c, x, y);
  }
  if (a < 0) {
    Z d = gcd(-a, b, c, x, y);
    x = -x;
    return d;
  }
  if (b < 0) {
    Z d = gcd(a, -b, c, x, y);
    y = -y;
    return d;
  }
  if (a > b) {
    Z d = gcd(b, a, c, y, x);
    return d;
  }
  if (b == 0) {
    x = 0;
    y = 0;
    if (c == 0)
      return 1;
    else
      return -1;
  }
  return gcd_primitive(a, b, c, x, y);
}

int main(void) {
  Z x, y;

  cout << gcd(9223372036854775805, 9223372036854775803, 9223372036854775807, x,
              y) << endl;
  cout << x << ", " << y << endl;
}
