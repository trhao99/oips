#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
string add(string a, string b) {
  string res, c, d;
  int t, jw = 0;
  if (a.size() > b.size()) {
    c = a;
    d = b;
  } else {
    c = b;
    d = a;
  }
  reverse(c.begin(), c.end());
  reverse(d.begin(), d.end());
  for (int i = 0; i < d.size(); i++) {
    t = jw + (c[i] - '0') + (d[i] - '0');
    jw = t / 10;
    res.insert(0, 1, (t % 10) + '0');
  }
  for (int i = d.size(); i < c.size(); i++) {
    t = jw + (c[i] - '0');
    jw = t / 10;
    res.insert(0, 1, (t % 10) + '0');
  }
  if (jw != 0) {
    res.insert(0, 1, jw + '0');
  }
  return res;
}
int main() {
  string a, b;
  cin >> a >> b;
  printf("%s", add(a, b).c_str());
  return 0;
}