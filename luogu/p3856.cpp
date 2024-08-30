#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 1;
const int logn = 21;
int f[N][logn], Logn[N + 1];
int n, m;
void init() {
  Logn[1] = 0;
  Logn[2] = 1;
  for (int i = 3; i < N; i++)
    Logn[i] = Logn[i / 2] + 1;
}
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-')
      f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  return x * f;
}

int main() {
  int x, y, s;
  // cin >> n >> m;
  n = read();
  m = read();
  for (int i = 1; i <= n; i++)
    // cin >> f[i][0];
    f[i][0] = read();
  init();
  for (int j = 1; j <= logn; j++)
    for (int i = 1; i + (1 << j) - 1 <= n; i++)
      // [i+(1<<j)-1, (i+(1<<j)-1)+(1<<(j-1))]
      // 正好2^(j-1)长度的区间,若不减1则max后面的 f[i + (1 << (j - 1))][j - 1]
      // 区间会越界
      f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
  for (int i = 0; i < m; i++) {
    // cin >> x >> y;
    x = read();
    y = read();
    s = Logn[y - x + 1];
    printf("%d\n", max(f[x][s], f[y - (1 << s) + 1][s]));
  }
  return 0;
}
