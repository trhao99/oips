#include <bits/stdc++.h>

using namespace std;
const int N = 100;
const int D = 20;
int lg[N], values[D], logn[N];
//lg lower(log2(n)) + 1 , logn lower(log2(n))
int main() {
  int n;
  scanf("%d", &n);
  logn[1] = 0;
  logn[2] = 1;
  for (int i = 1; i <= n; i++) {
    lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
    values[lg[i]]++;
    if (i >= 3)
      logn[i] = logn[i / 2] + 1;
  }
  for (int i = 0; i < n; i++) {
    printf("lg[%d]=%d\t", i, lg[i]);
    printf("logn[%d]=%d\n", i, logn[i]);
  }
  // for(int i = 0; i < D; i++) {
  //     printf("values[%d]=%d\n",i, values[i]);
  // }
}
