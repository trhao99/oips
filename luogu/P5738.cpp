#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int main() {
  int n, m, dur_max = 0, dur_min = 10, t;
  double score = 0, max_score = 0;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    score = 0;
    dur_max = 0;
    dur_min = 10;
    for (int j = 0; j < m; j++) {
      cin >> t;
      score += t;
      dur_max = max(dur_max, t);
      dur_min = min(dur_min, t);
    }
    score = ((score - dur_max - dur_min) * 1.0) / (m - 2);
    max_score = max(max_score, score);
  }
  printf("%.2f", max_score);
  return 0;
}