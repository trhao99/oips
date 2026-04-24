#include <algorithm>
#include <bits/stdc++.h>
#include <cctype>
using namespace std;
int main() {
  string s;
  cin >> s;
  transform(s.begin(), s.end(), s.begin(),
            [](unsigned char c) {return toupper(c); });
  cout << s;
  return 0;
}