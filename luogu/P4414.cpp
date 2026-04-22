#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int main() {
  int a, b, c, x, z, d;
  char s[3];
  cin >> a >> b >> c;
  cin >> s[0] >> s[1] >> s[2];
  x = min(a, min(b, c));
  d = max(a, max(b, c));
  z = a + b + c - x - d;
  for (int i = 0; i < 3; i++) {
    if (s[i] == 'A') {
      printf("%d", x);
    }
    if (s[i] == 'B')
      printf("%d", z);
    if (s[i] == 'C')
      printf("%d", d);
    if(i != 2) printf(" ");
  }
  return 0;
}