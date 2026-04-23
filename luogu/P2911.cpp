#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int counts[81] = {0};
int main() {
  int s1, s2, s3, min_sum = 80, freq = 0;
  cin >> s1 >> s2 >> s3;
  for (int i = 1; i <= s1; i++) {
    for (int j = 1; j <= s2; j++) {
      for (int k = 1; k <= s3; k++) {
        counts[i + j + k]++;
      }
    }
  }
  for (int i = 0; i < 81; i++) {
    if (counts[i] > freq) {
      min_sum = i;
      freq = counts[i];
    }
  }
  printf("%d", min_sum);
  return 0;
}