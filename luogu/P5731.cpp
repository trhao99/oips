#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int direct[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int res[10][10];
int main() {
  int n, i = 0, j = 0, dur = 1, dur_direct = 0, next_i, next_j;
  cin >> n;
  res[i][j] = dur++;
  while (true) {
    next_i = i + direct[dur_direct][0];
    next_j = j + direct[dur_direct][1];
    if (next_i >= n || next_i < 0 || next_j >= n || next_j < 0 ||
        res[next_i][next_j] != 0) {
      dur_direct = (dur_direct + 1) % 4;
    }
    next_i = i + direct[dur_direct][0];
    next_j = j + direct[dur_direct][1];
    if (res[next_i][next_j] != 0) {
      break;
    } else {
      res[next_i][next_j] = dur++;
      i = next_i;
      j = next_j;
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      cout << ' ';
      if (res[i][j] < 10)
        cout << ' ';     // 注意特判
      cout << res[i][j]; // 输出答案
    }
    printf("\n");
  }
  return 0;
}