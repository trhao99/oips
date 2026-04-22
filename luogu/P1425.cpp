#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int main() {
  int a, b, c, d, s_m, e_m, dur;
  cin >> a >> b >> c >> d;
  s_m = a * 60 + b;
  e_m = c * 60 + d;
  dur = e_m - s_m;
  printf("%d %d", (int)(floor(dur / 60.0)), dur % 60);
  return 0;
}