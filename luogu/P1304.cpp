#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
const int N = 1e4 + 1;
bool primes[N]; // false是质数
int main() {
  primes[1] = true;
  for (int i = 2; i < N; i++) {
    int t = 2;
    if (!primes[i]) {
      while (t * i < N) {
        primes[t * i] = true;
        t++;
      }
    }
  }
  int n, end, num;
  cin >> n;
  end = (n - 2) / 2;
  for (int i = 1; i <= end; i++) {
    num = 2 * i + 2;
    for (int j = 2; j < num - 1; j++) {
      if (!primes[j] && !primes[num - j]) {
        printf("%d=%d+%d\n", num, j, num - j);
        break;
      }
    }
  }
  return 0;
}