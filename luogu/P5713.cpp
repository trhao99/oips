#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, t1, t2;
  cin >> n;
  t1 = n * 5;
  t2 = n * 3 + 11;
  if (t1 < t2)
    printf("Local");
  else
    printf("Luogu");
  return 0;
}