#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int main() {
  int n, num = 1;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%02d", num++);
    }
    printf("\n");
  }
  printf("\n");
  num = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (n - i - 1); j++) {
      printf("  ");
    }
    for (int j = 0; j <= i; j++) {
      printf("%02d", num++);
    }
    printf("\n");
  }
  return 0;
}