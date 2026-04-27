#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
char p[400][26];
int c1[26] = {0};
int main() {
  string s;
  int max_count = 0;
  for (int i = 0; i < 26; i++) {
    p[399][i] = (char)('A' + i);
  }
  for (int i = 0; i < 4; i++) {
    getline(cin, s);
    for (char c : s) {
      if (c >= 'A' && c <= 'Z') {
        c1[c - 'A']++;
        p[399 - c1[c - 'A']][c - 'A'] = '*';
        max_count = max(max_count, c1[c - 'A']);
      }
    }
  }
  for (int i = 399 - max_count; i <= 399; i++) {
    for (int j = 0; j < 26; j++) {
      if (p[i][j] == 0)
        printf(" ");
      else
        printf("%c", p[i][j]);
      printf(" ");
    }
    printf("\n");
  }
  return 0;
}