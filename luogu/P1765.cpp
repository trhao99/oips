#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int res = 0;
  getline(cin, s);
  for (char c : s) {
    if (c == ' ')
      res++;
    if (c == 'a' || c == 'd' || c == 'g' || c == 'j' || c == 'm' || c == 'p' ||
        c == 't' || c == 'w') {
      res++;
    }
    if (c == 'b' || c == 'e' || c == 'h' || c == 'k' || c == 'n' || c == 'q' ||
        c == 'u' || c == 'x') {
      res += 2;
    }
    if (c == 'c' || c == 'f' || c == 'i' || c == 'l' || c == 'o' || c == 'r' ||
        c == 'v' || c == 'y') {
      res += 3;
    }
    if (c == 's' || c == 'z') {
      res += 4;
    }
  }
  printf("%d", res);
  return 0;
}