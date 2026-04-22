#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int main() {
  const double bj = 19.0;
  int y, j, gj;
  cin >> y >> j;
  gj = y * 10 + j;
  printf("%d", (int)(floor(gj / bj)));
  return 0;
}