#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
using namespace std;
const int N = 2000000 + 1;
bool lights[N]; // false是关
int main() {
  int n, t, index;
  double a;
  cin >> n;
  for (int j = 0; j < n; j++) {
    cin >> a >> t;
    for (int i = 1; i <= t; i++) {
      index = (int)floor(i * a);
      lights[index] = !lights[index];
    }
  }
  for (int i = 1; i < N; i++) {
    if (lights[i]) {
      printf("%d", i);
      return 0;
    }
  }
  return 0;
}