#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, n1, p1, n2, p2, n3, p3;
  double x1, x2, x3, r;
  cin >> n;
  cin >> n1 >> p1;
  cin >> n2 >> p2;
  cin >> n3 >> p3;
  x1 = p1 * 1.0 / n1;
  x2 = p2 * 1.0 / n2;
  x3 = p3 * 1.0 / n3;
  r = ceil(n * 1.0 / n1) * p1;
  r = min(r, ceil(n * 1.0 / n2) * p2);
  r = min(r, ceil(n * 1.0 / n3) * p3);
  printf("%d", (int)r);
  return 0;
}