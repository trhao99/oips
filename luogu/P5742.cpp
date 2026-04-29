#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int main() {
  int n;
  int _, xy, sz;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> _ >> xy >> sz;
    if (xy + sz > 140 && xy * 7 + sz * 3 >= 800) {
      printf("Excellent\n");
    } else {
      printf("Not excellent\n");
    }
  }
  return 0;
}