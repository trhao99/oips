// https://loj.ac/p/515
#include <bits/stdc++.h>
#include <bitset>

using namespace std;
const int N = 101;
bitset<N * N * N> f[N];
int a[N], b[N];
int main() {
  int i, j, n;
  cin >> n;
  for (i = 1; i <= n; i++)
    cin >> a[i] >> b[i];
  f[0][0] = 1;
  for (i = 1; i <= n; i++) {
    for (j = a[i]; j <= b[i]; j++) {
      f[i] |= (f[i - 1] << (j * j));
    }
  }
  cout << f[n].count() << endl;
  return 0;
}
