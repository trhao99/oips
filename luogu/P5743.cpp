#include <bits/stdc++.h>
using namespace std;
int resolve(int n) { return (n + 1) * 2; }
int main() {
  // (x/2 -1)/2-1
  int n, res = 1;
  cin >> n;
  while (n > 1) {
    res = resolve(res);
    n--;
  }
  printf("%d", res);
  return 0;
}