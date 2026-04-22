#include <bits/stdc++.h>
using namespace std;
bool pr(int y) { return y % 4 == 0 && y % 100 != 0; }
bool sr(int y) { return y % 400 == 0; }
int main() {
  int y;
  cin >> y;
  printf("%d", pr(y) || sr(y) ? 1 : 0);
  return 0;
}