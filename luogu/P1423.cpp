#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int main() {
  double speed = 2.0, path = 2.0, s;
  int step = 1;
  cin >> s;
  while (path < s) {
    speed *= 0.98;
    path += speed;
    step++;
  }
  printf("%d\n",step);
  return 0;
}