#include <bits/stdc++.h>
#include <cmath>
using namespace std;
double dis(double x1, double y1, double x2, double y2) {
  return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
int main() {
  double x1, x2, x3, y1, y2, y3, res;

  cin >> x1 >> y1;
  cin >> x2 >> y2;
  cin >> x3 >> y3;
  res = dis(x1, y1, x2, y2) + dis(x1, y1, x3, y3) + dis(x2, y2, x3, y3);
  printf("%.2f", res);
  return 0;
}