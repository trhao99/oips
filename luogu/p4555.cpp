#include <algorithm>
#include <bits/stdc++.h>
#include <cstring>
#include <vector>

using namespace std;

const int N = 1e5 + 1;
char s[N];
vector<int> d1(N), d2(N), maxEnd(N), minStart(N, N);
int res;
void clacD1(int n) {
  for (int i = 0, l = 0, r = -1; i < n; i++) {
    int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
    for (int t = 0; t <= k - 1; t++) {
      minStart[i + t] = min(minStart[i + t], i - t);
      maxEnd[i - t] = max(maxEnd[i - t], i + t);
    }
    while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
      k++;
      minStart[i + k] = min(minStart[i + k], i - k);
      maxEnd[i - k] = max(maxEnd[i - k], i + k);
    }
    d1[i] = k--;
    if (i + k > r) {
      l = i - k;
      r = i + k;
    }
  }
}
void clacD2(int n) {
  for (int i = 0, l = 0, r = -1; i < n; i++) {
    int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
    for (int t = 0; t <= k - 1; t++) {
      minStart[i + t] = min(minStart[i + t], i - t - 1);
      maxEnd[i - t - 1] = max(maxEnd[i - t - 1], i + t);
    }
    while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
      k++;
      minStart[i + k] = min(minStart[i + k], i - k - 1);
      maxEnd[i - k - 1] = max(maxEnd[i - k - 1], i + k);
    }
    d2[i] = k--;
    if (i + k > r) {
      l = i - k - 1;
      r = i + k;
    }
  }
}
int solve(int n) {
  int res = 0;
  if (n == 2)
    return 2;
  for (int i = 1; i < n; i++) {
    res = max(maxEnd[i] - minStart[i - 1] + 1, res);
  }
  return res;
}
// wrong
int main() {
  cin >> s;
  int len = strlen(s);
  clacD1(len);
  clacD2(len);
  int res = solve(len);
  cout << res;
  return 0;
}