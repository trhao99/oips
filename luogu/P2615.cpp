#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
const int N = 39;
int hf[N][N] = {0};
int main() {
  int n, last_row_index = -1, last_col_index = -1, dur = 1, dur_row_index,
         dur_col_index;
  cin >> n;
  hf[0][n / 2] = 1;
  last_row_index = 0;
  last_col_index = n / 2;
  dur++;
  while (dur <= n * n) {
    if (last_row_index == 0 && last_col_index != (n - 1)) {
      dur_row_index = n - 1;
      dur_col_index = last_col_index + 1;
    } else if (last_col_index == (n - 1) && last_row_index != 0) {
      dur_col_index = 0;
      dur_row_index = last_row_index - 1;
    } else if (last_row_index == 0 && last_col_index == (n - 1)) {
      dur_col_index = last_col_index;
      dur_row_index = last_row_index + 1;
    } else if (last_row_index != 0 && last_col_index != (n - 1)) {
      if (hf[last_row_index - 1][last_col_index + 1] == 0) {
        dur_row_index = last_row_index - 1;
        dur_col_index = last_col_index + 1;
      } else {
        dur_row_index = last_row_index + 1;
        dur_col_index = last_col_index;
      }
    }
    hf[dur_row_index][dur_col_index] = dur++;
    last_row_index = dur_row_index;
    last_col_index = dur_col_index;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", hf[i][j]);
    }
    printf("\n");
  }
  return 0;
}