#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int counts[20000] = {0};
int nums[100] = {0};
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
    for (int k = 0; k < i; k++) {
      counts[nums[i] + nums[k]]++;
    }
  }
  int res = 0;
  for (int i = 0; i < n; i++) {
    if (counts[nums[i]] != 0)
      res++;
  }
  printf("%d", res);
  return 0;
}