#include <bits/stdc++.h>
#include <cstddef>
#include <cstdio>
#include <string>
using namespace std;
string s;
int calc_count(int n) {
  if (n == 1)
    return 0;
  int res = 0;
  for (int i = 0; i < n - 1; i++)
    if (s[i] == 'V' && s[i + 1] == 'K')
      res++;
  return res;
}
int main() {
  int n, res;
  cin >> n;
  cin >> s;
  // VV,KK, +1
  // VK,KV +0;
  res = calc_count(n);
  for (int i = 0; i < n - 1; i++)
    if (s[i] == 'V' && s[i + 1] == 'K') {
      s[i] = 'X';
      s[i + 1] = 'X';
    }
  for (int i = 0; i < n - 1; i++) {
    if ((s[i] == 'V' && s[i + 1] == 'V') || (s[i] == 'K' && s[i + 1] == 'K')){
      res++;
      break;
    }
  }
  printf("%d", res);
  return 0;
}