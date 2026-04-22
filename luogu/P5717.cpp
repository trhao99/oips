#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
bool sj(int l1, int l2, int l3) {
  return l1 + l2 > l3 && l1 + l3 > l2 && l2 + l3 > l1;
}
bool rj(int l1, int l2, int l3) {
  int d, z, c;
  d = min(l1, min(l2, l3));
  c = max(l1, max(l2, l3));
  z = l1 + l2 + l3 - d - c;
  return d * d + z * z > c * c;
}
bool zj(int l1, int l2, int l3) {
  int d, z, c;
  d = min(l1, min(l2, l3));
  c = max(l1, max(l2, l3));
  z = l1 + l2 + l3 - d - c;
  return d * d + z * z == c * c;
}
bool dj(int l1, int l2, int l3) {
  int d, z, c;
  d = min(l1, min(l2, l3));
  c = max(l1, max(l2, l3));
  z = l1 + l2 + l3 - d - c;
  return d * d + z * z < c * c;
}
bool dy(int l1, int l2, int l3) { return l1 == l2 || l1 == l3 || l2 == l3; }
bool db(int l1, int l2, int l3) { return l1 == l2 && l1 == l3; }
int main() {
  int l1, l2, l3;
  cin >> l1 >> l2 >> l3;
  if (!sj(l1, l2, l3)) {
    printf("Not triangle");
  } else {
    if (zj(l1, l2, l3))
      printf("Right triangle\n");
    if (rj(l1, l2, l3))
      printf("Acute triangle\n");
    if (dj(l1, l2, l3))
      printf("Obtuse triangle\n");
    if(dy(l1,l2,l3))
        printf("Isosceles triangle\n");
    if(db(l1,l2,l3))
        printf("Equilateral triangle\n");
  }
  return 0;
}