#include <bits/stdc++.h>
#include <limits>

using namespace std;
// (a^b) % m = ((a % m)^b)%m
// a^b
bool overflow(long long a, long long b) {
  if (a == 1 || a == 0 || b == 0 || b == 1)
    return false;
  long long limit = numeric_limits<long long>::max();
  long long maxB = log(limit) / log(a);
  return b > maxB;
}
bool overflow_mult(long long a, long long b) {
  long long limit = numeric_limits<long long>::max();
  return (limit / b) < a;
}
long long fastPow(long long a, long long b) {
  if (b == 0)
    return 1ll;
  if (b == 1)
    return a;
  if (b == 2)
    return a * a;
  long long halfAns;
  if (!(b % 2)) {
    halfAns = fastPow(a, b >> 1);
    return halfAns * halfAns;
  } else {
    halfAns = fastPow(a, (b - 1) >> 1);
    return halfAns * halfAns * a;
  }
}
// pow and mod
long long pam(long long a, long long b, long long m) {
  //   cout << a << " " << b << " " << m << endl;
  if (!overflow(a, b))
    return fastPow(a, b) % m;
  else {
    long long h;
    if (!(b % 2)) {
      h = pam(a, b >> 1, m);
    //   if (overflow(h, 2ll))
        // cout << h << endl;
      return (h * h) % m;
    } else {
      h = pam(a, (b - 1) >> 1, m);
    //   if (overflow_mult((h * h) % m, a % m))
        // cout << h << " " << a << endl;
      return ((h * h) % m * ((a % m) % m)) % m;
    }
  }
}
int main() {
//   freopen("P1226_7.in", "r", stdin);
  //   freopen("P1908_1.out", "w", stdout);
  int n;
  long long a, b, p, ans;
  cin >> a >> b >> p;
//   cout << a << "^" << b << " " << "mod " << p << "=?" << endl;
  ans = pam(a, b, p);
  cout << a << "^" << b << " " << "mod " << p << "=" << ans << endl;
  return 0;
}