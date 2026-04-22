#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int resverse(int num) {
  if (num == 0)
    return 0;
  int flag = 1;
  if (num < 0) {
    num = num * -1;
    flag = -1;
  }
  int res = 0;
  while (num != 0) {
    int digit = 0;
    digit = num % 10;
    res = res * 10 + digit;
    num /= 10;
  }
  return flag * res;
}
int main() { 
    int num;
    cin >> num;
    num = resverse(num);
    printf("%d\n",num);
    return 0; }