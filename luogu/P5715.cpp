#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, mi, ma, z;
  cin >> a >> b >> c;
  mi = min(a, min(b, c));
  ma = max(a, max(b, c));
  z = a + b + c - mi - ma;
  printf("%d %d %d", mi, z, ma);
  return 0;
}