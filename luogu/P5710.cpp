#include <bits/stdc++.h>
using namespace std;
bool x1(int x) { return x % 2 == 0; }
bool x2(int x) { return x > 4 && x <= 12; }
int main() {
  int x, r1, r2, r3, r4;
  cin >> x;
  r1 = x1(x) && x2(x) ? 1 : 0;
  r2 = x1(x) || x2(x) ? 1 : 0;
  r3 = (x1(x) && !x2(x)) || (!x1(x) && x2(x)) ? 1 : 0;
  r4 = !x1(x) && !x2(x) ? 1 : 0;
  printf("%d %d %d %d", r1, r2, r3, r4);
  return 0;
}