#include <bits/stdc++.h>
using namespace std;
int main() {
  double sn = 0, k;
  int n = 1;
  cin >> k;
  while (sn <= k) {
    sn += (1.0 / n);
    n++;
  }
  printf("%d", n - 1);
  return 0;
}