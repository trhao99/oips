#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
using namespace std;
const int N = 1e5;
bool nums[N]; // false的是素数
int main() {
  int l, l1, i = 2, t, res = 0, res_count = 0;
  cin >> l;
  l1 = sqrt(l);
  for (i = 2; i <= l1; i++) {
    t = 2;
    if (nums[i] == false) {
      while (t * i <= l) {
        nums[t * i] = true;
        t++;
      }
    }
  }
  i = 2;
  for (i = 2; i < N; i++) {
    if (!nums[i]) {
      if (res + i <= l) {
        res += i;
        res_count++;
        printf("%d\n", i);
      } else {
        break;
      }
    }
  }
  printf("%d\n", res_count);
  return 0;
}