#include <bits/stdc++.h>

using namespace std;
int hIndex(vector<int> &citations) {
  int n = citations.size();
  vector<int> cnt(n + 1);
  for (int i = 0; i < n; i++) {
    cnt[min(citations[i], n)]++;
  }
  int s = 0;
  for (int i = n; i >= 0; i--) {
    s += cnt[i];
    if (s >= i) {
      return i;
    }
  }
  return 0;
}
int main() { return 0; }