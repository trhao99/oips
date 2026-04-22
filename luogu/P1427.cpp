#include <bits/stdc++.h>
#include <cstdio>
#include <stack>
using namespace std;
int main() {
  int t;
  stack<int> a;
  for (int i = 0; i < 100; i++) {
    cin >> t;
    if (t == 0)
      break;
    else {
      a.push(t);
    }
  }
  while (!a.empty()) {
    printf("%d ", a.top());
    a.pop();
  }
  return 0;
}