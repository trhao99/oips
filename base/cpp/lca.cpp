#include <cmath>
#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
const int N = 6e5;
int n, m, s, t, tot = 0, f[N][20], d[N], ver[2 * N], Next[2 * N], head[N];
queue<int> q;
void add(int x, int y) {
  ver[++tot] = y, Next[tot] = head[x], head[x] = tot;
} // 邻接表存边操作。由于只求LCA时不关心边权，因此可以不存边权
void bfs() {
  q.push(s);
  d[s] = 1; // 将根节点入队并标记
  while (q.size()) {
    int x = q.front();
    q.pop(); // 取出队头
    for (int i = head[x]; i; i = Next[i]) {
      int y = ver[i];
      if (d[y])
        continue;
      d[y] = d[x] + 1;
      f[y][0] = x; // 初始化，因为y的父亲节点就是x
      for (int j = 1; j <= t; j++)
        f[y][j] = f[f[y][j - 1]][j - 1]; // 递推f数组
      q.push(y);
    }
  }
}
int lca(int x, int y) {
  if (d[x] > d[y])
    swap(x, y);
  for (int i = t; i >= 0; i--)
    if (d[f[y][i]] >= d[x])
      y = f[y][i]; // 尝试上移y
  if (x == y)
    return x; // 若相同说明找到了LCA
  for (int i = t; i >= 0; i--)
    if (f[x][i] != f[y][i]) {
      x = f[x][i], y = f[y][i];
    } // 尝试上移x、y并保持它们不相遇
  return f[x][0]; // 当前节点的父节点即为LCA
}
int main() {
  cin >> n >> m >> s;
  t = log2(n) + 1;
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    add(x, y), add(y, x);
  }
  bfs();
  while (m--) {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", lca(a, b));
  }
  return 0;
}
