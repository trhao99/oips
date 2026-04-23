#include <bits/stdc++.h>
using namespace std;
const int N = 100+1;
bool m1[N][N]; // false是黑暗
int main() {
  int n, m, k, xi, yi, oi, pi, res = 0;
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    cin >> xi >> yi;
    m1[xi][yi] = true;

    m1[max(1, xi - 1)][yi] = true;
    m1[max(1, xi - 2)][yi] = true;
    m1[min(n  , xi + 1)][yi] = true;
    m1[min(n , xi + 2)][yi] = true;

    m1[xi][max(1, yi - 1)] = true;
    m1[xi][max(1, yi - 2)] = true;
    m1[xi][min(n , yi + 1)] = true;
    m1[xi][min(n , yi + 2)] = true;

    m1[max(1, xi - 1)][max(1, yi - 1)] = true;
    m1[max(1, xi - 1)][min(n , yi + 1)] = true;
    m1[min(n , xi + 1)][max(1, yi - 1)] = true;
    m1[min(n , xi + 1)][min(n , yi + 1)] = true;
  }
  for (int i = 0; i < k; i++) {
    cin >> oi >> pi;
    m1[max(1, oi - 2)][max(1, pi - 2)] = true;
    m1[max(1, oi - 2)][max(1, pi - 1)] = true;
    m1[max(1, oi - 2)][pi] = true;
    m1[max(1, oi - 2)][min(n , pi + 1)] = true;
    m1[max(1, oi - 2)][min(n , pi + 2)] = true;

    m1[max(1, oi - 1)][max(1, pi - 2)] = true;
    m1[max(1, oi - 1)][max(1, pi - 1)] = true;
    m1[max(1, oi - 1)][pi] = true;
    m1[max(1, oi - 1)][min(n , pi + 1)] = true;
    m1[max(1, oi - 1)][min(n , pi + 2)] = true;

    m1[oi][max(1, pi - 2)] = true;
    m1[oi][max(1, pi - 1)] = true;
    m1[oi][pi] = true;
    m1[oi][min(n , pi + 1)] = true;
    m1[oi][min(n , pi + 2)] = true;

    m1[min(n , oi + 1)][max(1, pi - 2)] = true;
    m1[min(n , oi + 1)][max(1, pi - 1)] = true;
    m1[min(n , oi + 1)][pi] = true;
    m1[min(n , oi + 1)][min(n , pi + 1)] = true;
    m1[min(n , oi + 1)][min(n , pi + 2)] = true;

    m1[min(n , oi + 2)][max(1, pi - 2)] = true;
    m1[min(n , oi + 2)][max(1, pi - 1)] = true;
    m1[min(n , oi + 2)][pi] = true;
    m1[min(n , oi + 2)][min(n , pi + 1)] = true;
    m1[min(n , oi + 2)][min(n , pi + 2)] = true;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (!m1[i][j])
        res++;
    }
  }
  printf("%d", res);
  return 0;
}