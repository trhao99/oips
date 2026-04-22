#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k = 1, res = 0;
  cin >> n;
  while (k <= n) {
    res += k;
    k++;
  }
  printf("%d", res);
  return 0;
}