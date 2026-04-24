#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
bool primes[101]; // false是质数
int counts[27];
int main() {
  string s;
  int maxn = 0, minn = 100;
  primes[0] = true;
  primes[1] = true;
  int t = 2;
  for (int i = 1; i < 101; i++) {
    if (!primes[i]) {
      while (t * i < 101) {
        primes[t * i] = true;
        t++;
      }
    }
  }
  cin >> s;
  for (char c : s) {
    counts[c - 'a']++;
  }
  for (int i = 0; i < 26; i++) {
    maxn = max(maxn, counts[i]);
    if (counts[i] != 0)
      minn = min(minn, counts[i]);
  }
  if (!primes[maxn - minn]) {
    printf("Lucky Word\n%d", maxn - minn);
  } else {
    printf("No Answer\n0");
  }
  return 0;
}