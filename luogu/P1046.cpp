#include <bits/stdc++.h>
using namespace std;
int main() {
  int tree[10], n, r = 0;
  for (int i = 0; i < 10; i++)
    cin >> tree[i];
  cin >> n;
  n += 30;
  for (int i = 0; i < 10; i++) {
    if (tree[i] <= n)
      r++;
  }
  printf("%d", r);
  return 0;
}