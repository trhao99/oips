#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main() {
  int s, v, t, h, m;
  cin >> s >> v;
  t = ceil((double)s / v) + 10;
  if (t > 8 * 60) {
    h = 24 - ceil((t - 8 * 60) / 60.0);
  } else {
    h = 8 - ceil(t / 60.0);
  }
  m = t % 60 == 0 ? 0 : 60 - (t % 60);
  printf("%02d:%02d", h, m);
  return 0;
}