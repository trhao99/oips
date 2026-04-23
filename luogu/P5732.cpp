#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int res[20][20] = {0};
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    res[i][0] = 1;
    res[i][i] = 1;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      if (res[i][j] == 0) {
        res[i][j] = res[i - 1][j] + res[i - 1][j - 1];
      }
      printf("%d ", res[i][j]);
    }
    printf("\n");
  }
  return 0;
}