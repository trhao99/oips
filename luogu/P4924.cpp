#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
const int N = 500 + 1;
int m[N][N];
void init_m(int n) {
  int num = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      m[i][j] = num++;
    }
  }
}
void rotate90_s(int x, int y, int len) {
  int t;
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < i; j++) {
      // m[x+i][y+j] 和 m[x+j][y+i]
      t = m[x + i][y + j];
      m[x + i][y + j] = m[x + j][y + i];
      m[x + j][y + i] = t;
    }
  }
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len / 2; j++) {
      // m[x+i][y+j]和m[x+i][y+len-1-j]
      t = m[x + i][y + j];
      m[x + i][y + j] = m[x + i][y + len - 1 - j];
      m[x + i][y + len - 1 - j] = t;
    }
  }
}
void rotate90_n(int x, int y, int len) {
  int t;
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < i; j++) {
      // m[x+i][y+len-1-j]和m[x+j][y+len-1-i]
      t = m[x + i][y + len - 1 - j];
      m[x + i][y + len - 1 - j] = m[x + j][y + len - 1 - i];
      m[x + j][y + len - 1 - i] = t;
    }
  }
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len / 2; j++) {
      // m[x+i][y+j]和m[x+i][y+len-1-j]
      t = m[x + i][y + j];
      m[x + i][y + j] = m[x + i][y + len - 1 - j];
      m[x + i][y + len - 1 - j] = t;
    }
  }
}
void print(int n) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      printf("%d ", m[i][j]);
    }
    printf("\n");
  }
}
int main() {
  int n, m1, x, y, r, z, x0, y0;
  cin >> n >> m1;
  init_m(n);
  for (int i = 0; i < m1; i++) {
    cin >> x >> y >> r >> z;
    x0 = x - r;
    y0 = y - r;
    if (z == 0)
      rotate90_s(x0, y0, 2 * r + 1);
    if (z == 1)
      rotate90_n(x0, y0, 2 * r + 1);
  }
  print(n);
  return 0;
}