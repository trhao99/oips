#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
using namespace std;
bool isLeapYear(int year) {
  return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
int main() {
  int x, y, count = 0;
  vector<int> res_years;
  cin >> x >> y;
  for (int i = x; i <= y; i++) {
    if (isLeapYear(i)) {
      count++;
      res_years.push_back(i);
    }
  }
  printf("%d\n", count);
  for (int year : res_years) {
    printf("%d ", year);
  }
  return 0;
}