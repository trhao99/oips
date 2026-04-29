#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int main() {
  int n;
  cin >> n;
  int dur_y, dur_s, dur_w;
  int max_y = -1, max_s = -1, max_w = -1;
  string name, max_name;
  for (int i = 0; i < n; i++) {
    cin >> name >> dur_y >> dur_s >> dur_w;
    if ((dur_y + dur_s + dur_w) > (max_y + max_s + max_w)) {
      max_name = name;
      max_y = dur_y;
      max_s = dur_s;
      max_w = dur_w;
    }
  }
  printf("%s %d %d %d", max_name.c_str(), max_y, max_s, max_w);
  return 0;
}