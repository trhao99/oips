#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int main() {
  // x x+k x+2k x+3k x+4k x+5k x+6k = 7x+21k
  // (7x+21k)*52 = n => 52*7*(x+3k) = n
  int n, week_money, t;
  cin >> n;
  n /= (52 * 7);
  if(n<=103) printf("%d\n%d\n",n-3,1);
  else {//k!=1
    	if(n%3==0) printf("%d\n%d\n",99,(n-99)/3);
		if(n%3==1) printf("%d\n%d\n",100,(n-100)/3);
		if(n%3==2) printf("%d\n%d\n",98,(n-98)/3);
  }
  return 0;
}