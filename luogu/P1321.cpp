#include <bits/stdc++.h>
#include <cstddef>
#include <cstdio>
using namespace std;
int main() {
  string s;
  cin >> s;
  size_t s_len = s.size();
  int bc = 0, gc = 0;
  s = "." + s;

  for (int i = 1; i <= s_len; i++) {
    if (s[i] == 'b') {
      bc++;
    }
    if (s[i] == 'o' && s[i - 1] != 'b') {
      bc++;
    }
    if (s[i] == 'y' && s[i - 1] != 'o') {
      bc++;
    }
    if (s[i] == 'g') {
      gc++;
    }
    if (s[i] == 'i' && s[i - 1] != 'g') {
      gc++;
    }
    if (s[i] == 'r' && s[i - 1] != 'i') {
      gc++;
    }
    if (s[i] == 'l' && s[i - 1] != 'r') {
      gc++;
    }
  }
  printf("%d\n%d", bc, gc);
  return 0;
}