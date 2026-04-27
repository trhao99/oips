#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
const int N = 1e5 + 1;
bool primes[N]; // false 是质数
int main() {
  int n, t, t1 = 1;
  primes[1] = true;
  for (int i = 2; i < N; i++) {
    t1 = 2;
    if (!primes[i]) {
      while (t1 * i < N) {
        primes[t1 * i] = true;
        t1++;
      }
    }
  }
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t;
    if (!primes[t]) {
      printf("%d ", t);
    }
  }
  return 0;
}