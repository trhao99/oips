#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int main() {
  int dur_len = 0, max_len = 0, n, dur_num, last_num = -2;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> dur_num;
    if (dur_num == last_num + 1) {
      dur_len++;
    } else {
      dur_len = 1;
    }
    last_num = dur_num;
    max_len = max(max_len, dur_len);
  }
  printf("%d\n", max_len);
  return 0;
}