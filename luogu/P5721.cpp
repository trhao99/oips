#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int main() {
  int n, sn = 1;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i; j++) {
      printf("%02d", sn++);
    }
    printf("\n");
  }
  return 0;
}