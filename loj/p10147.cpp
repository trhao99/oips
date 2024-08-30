#include <bits/stdc++.h>

using namespace std;
const int INF = 0x7fffffff;
const int MAXN = 202;
int fMax[MAXN * 2][MAXN * 2], fMin[MAXN * 2][MAXN * 2], a[MAXN * 2];
int dfsMin(int L, int R) {
  if (fMin[L][R])
    return fMin[L][R];
  if (L == R)
    return fMin[L][R] = 0;
  int res = INF;
  for (int k = L; k < R; k++) {
    res = min(res, dfsMin(L, k) + dfsMin(k + 1, R) + a[R] - a[L - 1]);
  }
  fMin[L][R] = res;
  return res;
}
int dfsMax(int L, int R) {
  if (fMax[L][R])
    return fMax[L][R];
  if (L == R)
    return fMax[L][R] = 0;
  int res = 0;
  for (int k = L; k < R; k++) {
    res = max(res, dfsMax(L, k) + dfsMax(k + 1, R) + a[R] - a[L - 1]);
  }
  fMax[L][R] = res;
  return res;
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i + n] = a[i];
  }
  for (int i = 1; i <= 2 * n; i++)
    a[i] += a[i - 1];
  int resMin = INF;
  int resMax = 0;
  dfsMax(1, 2 * n);
  dfsMin(1, 2 * n);
  for (int i = 1; i <= n; i++) { // 因为是环，所以要遍历所有断点可能性
    resMax = max(resMax, fMax[i][i + n - 1]);
    resMin = min(resMin, fMin[i][i + n - 1]);
  }
  cout << resMin << "\n" << resMax;
  return 0;
}
