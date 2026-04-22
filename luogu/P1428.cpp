#include <bits/stdc++.h>
using namespace std;
int main() {
  int cute_levels[11] = {0};
  int res[101];
  int n, t;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t;
    res[i] = cute_levels[t];
    for (int j = t + 1; j < 11; j++) {
      cute_levels[j]++;
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", res[i]);
  }
  return 0;
}