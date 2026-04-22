#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int N = 1e3 + 1;
int y[N], s[N], w[N], z[N];
int main() {
  int n, res = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> y[i] >> s[i] >> w[i];
    z[i] = y[i] + s[i] + w[i];
  }
  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (abs(z[i] - z[j]) <= 10 && abs(y[i] - y[j]) <= 5 &&
          abs(s[i] - s[j]) <= 5 && abs(w[i] - w[j]) <= 5) {
        res++;
      }
    }
  }
  printf("%d",res);
  return 0;
}