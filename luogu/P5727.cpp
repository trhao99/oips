#include <bits/stdc++.h>
#include <cstdio>
#include <stack>
using namespace std;
int main() {
  stack<int> s;
  int n;
  cin >> n;
  s.push(n);
  while (n != 1) {
    if (n % 2 != 0) {
      n = n * 3 + 1;
    } else {
      n /= 2;
    }
    s.push(n);
  }
  while (!s.empty()) {
    printf("%d ", s.top());
    s.pop();
  }
  return 0;
}