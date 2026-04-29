#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
char m1[102][102] = {0};
int resolve(int i, int j) {
  int res = 0;
  if (m1[i - 1][j - 1] == '*')
    res++;
  if (m1[i - 1][j] == '*')
    res++;
  if (m1[i - 1][j + 1] == '*')
    res++;
  if (m1[i][j - 1] == '*')
    res++;
  if (m1[i][j + 1] == '*')
    res++;
  if (m1[i + 1][j - 1] == '*')
    res++;
  if (m1[i + 1][j] == '*')
    res++;
  if (m1[i + 1][j + 1] == '*')
    res++;
  return res;
}
int main() {
  int n, m;
  string s;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> s;
    for (int j = 1; j <= m; j++) {
      m1[i][j] = s[j - 1];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (m1[i][j] == '*') {
        printf("*");
      } else {
        printf("%d", resolve(i, j));
      }
    }
    printf("\n");
  }
  return 0;
}