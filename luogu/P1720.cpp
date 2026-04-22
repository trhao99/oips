#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int main() {
  int n;
  double fn;
  cin >> n;
  fn = (pow((1 + sqrt(5.0)) / 2, n) - pow((1 - sqrt(5.0)) / 2, n)) / sqrt(5.0);
  printf("%.2f",fn);
  return 0;
}