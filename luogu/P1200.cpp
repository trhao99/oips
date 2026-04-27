#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int main() {
  string h, z;
  cin >> h;
  cin >> z;
  int hn = 1, zn = 1;
  for (char c : h) {
    hn *= (c - 'A' + 1);
  }
  for (char c : z) {
    zn *= (c - 'A' + 1);
  }
  if (hn % 47 == zn % 47) {
    printf("GO");
  } else {
    printf("STAY");
  }
  return 0;
}