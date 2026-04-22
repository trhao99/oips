#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, cur_price = 1, res = 0;
  cin >> k;
  while (k > cur_price) {
    res += (cur_price * cur_price);
    k-=cur_price;
    cur_price++;
  }
  res+=(k*cur_price);
  printf("%d",res);
  return 0;
}