#include <bits/stdc++.h>
#include <cstdio>
#include <map>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
int main() {
  map<string, int> w2n = {
      {"zero", 0},     {"one", 1},        {"two", 4},       {"three", 9},
      {"four", 16},    {"five", 25},      {"six", 36},      {"seven", 49},
      {"eight", 64},   {"nine", 81},      {"ten", 0},       {"eleven", 21},
      {"twelve", 44},  {"thirteen", 69},  {"fourteen", 96}, {"fifteen", 25},
      {"sixteen", 56}, {"seventeen", 89}, {"eighteen", 24}, {"nineteen", 61},
      {"twenty", 0},   {"a", 1},          {"both", 4},      {"another", 1},
      {"first", 1},    {"second", 4},     {"third", 9},
  };
  vector<int> l;
  string s, w;
  getline(cin, s);
  stringstream ss(s);
  while (ss >> w) {
    if (w2n.count(w) != 0) {
      l.push_back(w2n[w]);
    }
  }
  sort(l.begin(), l.end(),
       [](int a, int b) { return to_string(a) < to_string(b); });
  int res = 0;
  for (int num : l) {
    res = res * 10 + num;
  }
  printf("%d", res);
  return 0;
}