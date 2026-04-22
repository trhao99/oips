#include <bits/stdc++.h>
using namespace std;
int main() {
  char s[13];
  int r = 0, index = 1;
  for (int i = 0; i < 13; i++)
    cin >> s[i];
  for (int i = 0; i < 12; i++) {
    if (s[i] == '-')
      continue;
    r += ((s[i] - '0') * (index++));
  }
  if (r % 11 == (s[12] - '0') || (r % 11 == 10 && s[12] == 'X'))
    cout <<"Right";
  else {
    char ts = r % 11 == 10 ? 'X' : (r % 11) + '0';
    s[12] = ts;
    cout << s;
  }
  return 0;
}