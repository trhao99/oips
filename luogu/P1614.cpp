#include <bits/stdc++.h>
using namespace std;
int moods[3000] = {0};
int main() {
  int n, m, dur, min_num;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> moods[i];
    if (i > (m - 1)) {
      dur = dur + (moods[i] - moods[i - m]);
      min_num = min(min_num, dur);
    } else {
      dur += moods[i];
      min_num = dur;
    }
  }
  printf("%d", min_num);
  return 0;
}