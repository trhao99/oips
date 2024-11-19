#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int counter[N] = {0};

int main() {
  int n, f, t;
  cin >> n;
  int ans= 0;
  for (int i = 0; i < n - 1; i++) {
    cin >> f >> t;
    if(++counter[f] > ans) ans = counter[f];
    if(++counter[t] > ans) ans = counter[t];
  }
  cout << ans + 1;
  return 0;
}