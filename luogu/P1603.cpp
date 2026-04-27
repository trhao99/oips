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
  sort(l.begin(), l.end());
  string result;
  for (int i : l) {
    if (i < 10 && !result.empty())
      result += "0"; // 加先导零
    result += to_string(i);
  }
  unsigned long long No0 = result.find_first_not_of('0');
  if (No0 != string::npos)
    result = result.substr(No0);
  else
    result = "0";
  cout << result;
  return 0;
}