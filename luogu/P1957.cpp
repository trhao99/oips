#include <bits/stdc++.h>
#include <cstdio>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
void print_res(int type, int a1, int a2) {
  string s;
  if (type == 'a') {
    s = to_string(a1) + "+" + to_string(a2) + "=" + to_string(a1 + a2);
  } else if (type == 'b') {
    s = to_string(a1) + "-" + to_string(a2) + "=" + to_string(a1 - a2);
  } else if (type == 'c') {
    s = to_string(a1) + "*" + to_string(a2) + "=" + to_string(a1 * a2);
  }
  printf("%s\n%lu\n", s.c_str(), s.size());
}

int main() {
  int n, n1, n2;
  int last_clac;
  char c;
  cin >> n;
  string s;
  vector<int> l1;
  cin.ignore();
  for (int i = 0; i < n; i++) {
    getline(cin, s);
    stringstream ss(s);
    if (s[0] >= 'a' && s[0] <= 'z') {
      ss >> c >> n1 >> n2;
      l1.push_back(c);
      l1.push_back(n1);
      l1.push_back(n2);
      print_res(l1[0], l1[1], l1[2]);
      last_clac = l1[0];
    } else {
      ss >> n1 >> n2;
      l1.push_back(n1);
      l1.push_back(n2);
      print_res(last_clac, l1[0], l1[1]);
    }
    l1.clear();
  }
  return 0;
}