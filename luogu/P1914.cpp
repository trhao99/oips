#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  // 97-122
  string s;
  cin >> n;
  cin >> s;
  transform(s.begin(), s.end(), s.begin(),
            [](unsigned char c) { return (char)(97 + (c - 'a' + n) % 26); });
  cout << s;          
  return 0;
}