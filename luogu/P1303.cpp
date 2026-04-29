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
string mult(string a, string b) {
  if (a == "0" || b == "0")
    return "0";
  if (a == "1")
    return b;
  if (b == "1")
    return a;
  string res = "", c, d, base = "", t_res = "";
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
    t_res = "";
    for (int j = 0; j < c.size(); j++) {
      t = (d[i] - '0') * (c[j] - '0') + jw;
      jw = t / 10;
      t_res.insert(0, 1, (t % 10) + '0');
    }
    if (jw != 0) {
      t_res.insert(0, 1, jw + '0');
    }
    t_res += base;
    base += "0";
    res = add(res, t_res);
    jw=0;
  }
  return res;
}
int main() {
  string a, b;
  cin >> a >> b;
  printf("%s", mult(a, b).c_str());
  return 0;
}