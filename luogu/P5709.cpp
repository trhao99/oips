#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, t, s, r;
  cin >> m >> t >> s;
  r = m - (int)ceil((s * 1.0) / t);
  printf("%d", r > 0 ? r : 0);
  return 0;
}