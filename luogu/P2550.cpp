#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int counts[34] = {0};
int win_num[34] = {0};
int res_counts[7] = {0};
void clear_counts() {
  for (int i = 0; i < 34; i++)
    counts[i] = 0;
}
void count_win() {
  int res = 0;
  for (int i = 1; i <= 33; i++) {
    res += (min(win_num[i], counts[i]));
  }
  if (res != 0) {
    res_counts[7 - res]++;
  }
}
int main() {
  int n, t;
  cin >> n;
  for (int i = 0; i < 7; i++) {
    cin >> t;
    win_num[t]++;
  }
  for (int i = 0; i < n; i++) {
    clear_counts();
    for (int j = 0; j < 7; j++) {
      cin >> t;
      counts[t]++;
    }
    count_win();
  }
  for (int i = 0; i < 7; i++) {
    printf("%d ", res_counts[i]);
  }
  return 0;
}