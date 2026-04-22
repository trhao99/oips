#include <bits/stdc++.h>
using namespace std;
const int L = 1e4 + 2;
int diff[L] = {0}, a[L] = {0};
void add(int l, int r, int v) {
  diff[l] += v;
  if (r < L)
    diff[r + 1] -= v;
}
void prefix_sum(int end) {
  for (int i = 1; i <= end; i++) {
    a[i] = a[i - 1] + diff[i];
  }
}
int main() {
  int l, m, start, end;
  cin >> l >> m;
  for (int i = 0; i < m; i++) {
    cin >> start >> end;
    add(start, end, 1);
  }
  a[0] = diff[0];
  prefix_sum(l);
  int res = 0;
  for (int i = 0; i <= l; i++) {
    if (a[i] == 0)
      res++;
  }
  printf("%d", res);
  return 0;
}