#include <bits/stdc++.h>
using namespace std;
int main() {
  int xq = 0, t1, t2, r = 0;
  for (int i = 0; i < 7; i++) {
    cin >> t1 >> t2;
    if (t1 + t2 > xq && t1 + t2 > 8) {
      r = i + 1;
      xq = t1 + t2;
    }
  }
  printf("%d", r);
  return 0;
}