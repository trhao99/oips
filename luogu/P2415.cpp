#include <bits/stdc++.h>
#include <cstdio>
#include <sstream>
#include <string>
using namespace std;
int main() {
  unsigned long long t, sum1 = 0, count = 0, res;
  string s;
  getline(cin, s);
  stringstream ss(s);
  while (ss >> t) {
    sum1 += t;
    count++;
  }
  res = sum1 * pow(2, count) / 2;
  printf("%llu", res);
  return 0;
}