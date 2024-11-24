#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const long long N = 1e9 + 1;
long long x[N];
long long solve(long long rows, long long rs) {
  long long sum = 0, res = 0;
  for (long long i = 0; i < rs; i++) {
    sum = max(sum + x[i], 0ll);
    if (sum >= rows) {
      res++;
      sum = 0ll;
    }
  }
  return res;
}
int main() {
  long long l = 1, r = 1e18, mid, t, lAns = -1ll, rAns;
  long long rs, k;
  cin >> rs >> k;
  for (long long i = 0; i < rs; i++) {
    cin >> x[i];
  }
  while (l <= r) {
    mid = (l + r) >> 1;
    t = solve(mid,rs);
    if (t <= k) { // mid太大了
      r = mid - 1;
      if (t == k)
        lAns = mid;
    } else
      l = mid + 1;
  }
  l = 1ll, r = 1e18;
  while (l <= r) {
    mid = (l + r) >> 1;
    t = solve(mid,rs);
    if (t >= k) { // mid太小了
      l = mid + 1;
      if (t == k)
        rAns = mid;
    } else
      r = mid - 1;
  }
  if (lAns == -1ll)
    cout << -1;
  else
    cout << lAns << " " << rAns << endl;
  return 0;
}