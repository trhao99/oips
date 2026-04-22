#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, cs = 0;
  cin >> n;
  while (n != 1) {
    n = floor(n / 2);
    cs++;
  }
  printf("%d", cs+1);
  return 0;
}