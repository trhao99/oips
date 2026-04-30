#include <bits/stdc++.h>
#include <cstdio>
#include <string>
using namespace std;
int main() {
  int n, x;
  bool first = true, minus = false;
  string symbol, num_str, power;
  cin >> n;
  for (int i = n; i >= 0; i--) {
    cin >> x;
    if (x != 0) {
      if (x < 0)
        symbol = "-";
      else {
        if (!first)
          symbol = "+";
      }

      if ((x == 1 || x == -1) && i != 0) {
        num_str = "";
      } else {
        num_str = to_string(abs(x));
      }

      if (i == 1) {
        power = "x";
      } else if (i == 0) {
        power = "";
      } else {
        power = "x^" + to_string(i);
      }
      string res = symbol + num_str + power;
      printf("%s", res.c_str());
      if (first)
        first = false;
    }
  }
  return 0;
}