#include <bits/stdc++.h>
#include <cstdio>
#include <sstream>
#include <vector>
using namespace std;
int a = 0, b = 0, c = 0;
vector<string> split(const string &str, char delimiter) {
  vector<string> result;
  stringstream ss(str);
  string token;
  while (getline(ss, token, delimiter)) {
    result.push_back(token);
  }
  return result;
}
int main() {
  string s;
  getline(cin, s);
  char key, cvalue;
  int value;
  vector<string> sl = split(s, ';');
  for (string s1 : sl) {
    if (s1 != "") {
      key = s1[0];
      cvalue = s1[3];
      if (cvalue == 'a') {
        value = a;
      } else if (cvalue == 'b') {
        value = b;
      } else if (cvalue == 'c') {
        value = c;
      } else {
        value = (cvalue - '0');
      }
      if (key == 'a')
        a = value;
      if (key == 'b')
        b = value;
      if (key == 'c')
        c = value;
    }
  }
  printf("%d %d %d", a, b, c);
  return 0;
}