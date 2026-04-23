#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int counts[10] = {0};
void calc(int num) {
  while (num != 0) {
    counts[num % 10]++;
    num /= 10;
  }
}
int main() {
  int m, n;
  cin >> m >> n;
  for (int i = m; i <= n; i++) {
    calc(i);
  }
  for (int i = 0; i < 10; i++) {
    printf("%d ", counts[i]);
  }
  return 0;
}