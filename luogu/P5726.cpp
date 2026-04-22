#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int main() {
  int n, min_num = 10, max_num = 0, res=0, t;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t;
    min_num = min(min_num, t);
    max_num = max(max_num, t);
    res += t;
  }
  printf("%.2f", (res - min_num - max_num) / ((n - 2) * 1.0));
  return 0;
}