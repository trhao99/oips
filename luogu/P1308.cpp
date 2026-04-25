#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int main() {
  string w, s, tw;
  int count = 0;
  int  res_index = -1;
  cin >> w;
  cin.ignore();
  getline(cin, s);
  s += " ";
  transform(w.begin(), w.end(), w.begin(), ::tolower);
  transform(s.begin(), s.end(), s.begin(), ::tolower);
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == ' ') {
      if (tw == w) {
        count++;
        if(res_index==-1)res_index=i-w.size();
      }
      tw = "";
    } else {
      tw += s[i];
    }
  }
  if (res_index != string::npos) {
    printf("%d %lu", count, res_index);
  } else {
    printf("-1");
  }
  return 0;
}