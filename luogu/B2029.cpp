#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
using namespace std;
int main() {
  const double pi = 3.14;
  int h, r;
  double v;
  cin >> h >> r;
  v = (pi * r * r * h) / 1000;
  printf("%d", (int)(ceil(20 / v)));
  return 0;
}