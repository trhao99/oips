#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, x, z, d, j1_gcd, j2_gcd;
  float j1, j2;
  cin >> a >> b >> c;
  x = min(a, min(b, c));
  d = max(a, max(b, c));
  z = a + b + c - x - d;
  j1 = x / z;
  j2 = x / d;
  j1_gcd = gcd(x, z);
  j2_gcd = gcd(x, d);
  if (j1 < j2)
    printf("%d/%d", x / j1_gcd, z / j1_gcd);
  else
    printf("%d/%d", x / j2_gcd, d / j2_gcd);
  return 0;
}