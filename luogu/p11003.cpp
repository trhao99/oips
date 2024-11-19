#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e4 + 1;
struct {
  int x0, y0, x1, y1;
} recent[MAX_N];
int main() {
  int n, a, b, g, k, x, y;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b >> g >> k;
    recent[i].x0 = a;
    recent[i].y0 = b;
    recent[i].x1 = a + g;
    recent[i].y1 = b + k;
  }
  cin >> x >> y;
  for (int i = n; i >= 0; i--) {
    if (x <= recent[i].x1 && y <= recent[i].y1 && x >= recent[i].x0 &&
        y >= recent[i].y0) {
      cout << i + 1;
      return 0;
    }
  }
  cout << -1;
  return 0;
}