#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, a=0, b=0, a_num=0, b_num=0;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    if (i % k == 0) {
      a += i;
      a_num++;
    } else {
      b += i;
      b_num++;
    }
  }
  printf("%.1f %.1f", (a * 1.0) / a_num, (b * 1.0) / b_num);
  return 0;
}