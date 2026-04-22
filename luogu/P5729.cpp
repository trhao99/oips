#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
const int N = 20 + 2;
int diff[N][N][N] = {0};
void add(int x1, int y1, int z1, int x2, int y2, int z2, int v) {
  diff[x1][y1][z1] += v;

  diff[x2 + 1][y1][z1] -= v;
  diff[x1][y2 + 1][z1] -= v;
  diff[x1][y1][z2 + 1] -= v;

  diff[x2 + 1][y2 + 1][z1] += v;
  diff[x2 + 1][y1][z2 + 1] += v;
  diff[x1][y2 + 1][z2 + 1] += v;

  diff[x2 + 1][y2 + 1][z2 + 1] -= v;
}
// a 是原数组（或者用来存结果的数组）
// n, m, h 分别是长、宽、高
void restore(int n, int m, int h) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int k = 1; k <= h; k++) {
        // 三维前缀和公式
        // 当前值 = 差分值 + 三个方向的前缀和 - 三个方向重叠的部分 +
        // 重复减去的核心部分
        diff[i][j][k] += diff[i - 1][j][k] + diff[i][j - 1][k] +
                         diff[i][j][k - 1] - diff[i - 1][j - 1][k] -
                         diff[i - 1][j][k - 1] - diff[i][j - 1][k - 1] +
                         diff[i - 1][j - 1][k - 1];
      }
    }
  }
  // 此时 diff 数组里存的就是修改后的最终结果
}
int main() {
  int w, x, h, q, x1, y1, z1, x2, y2, z2;
  int res = 0;
  cin >> w >> x >> h;
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
    add(x1, y1, z1, x2, y2, z2, 1);
  }
  restore(w, x, h);
  for (int i = 1; i <= w; i++) {
    for (int j = 1; j <= x; j++) {
      for (int k = 1; k <= h; k++) {
        if (diff[i][j][k] == 0)
          res++;
      }
    }
  }
  printf("%d", res);
  return 0;
}