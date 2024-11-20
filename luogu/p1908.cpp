#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 1;
long long arr[N], tmpArr[N];
long long res = 0;
void merge(int low, int hign) {
  if (low >= hign)
    return;
  int mid = low + ((hign - low) / 2);
  merge(low, mid);
  merge(mid + 1, hign);
  int firstPtr = low, secondPtr = mid + 1, tmpPtr = 0;
  while (firstPtr <= mid && secondPtr <= hign) {
    if (arr[firstPtr] > arr[secondPtr]) {
      // first数组中有mid - firstPtr + 1
      // 个数比secondptr大。first每比secondptr大的数
      // 多一个，逆序数+1;
      res += (mid - firstPtr + 1);
      tmpArr[tmpPtr++] = arr[secondPtr++];
    } else {
      tmpArr[tmpPtr++] = arr[firstPtr++];
    }
  }
  if (firstPtr > mid) {
    while (secondPtr <= hign)
      tmpArr[tmpPtr++] = arr[secondPtr++];
  }
  if (secondPtr > hign) {
    res += (mid - firstPtr + 1) * (hign - secondPtr + 1);
    while (firstPtr <= mid)
      tmpArr[tmpPtr++] = arr[firstPtr++];
  }
  tmpPtr = 0;
  for (int i = low; i <= hign; i++) {
    arr[i] = tmpArr[tmpPtr++];
  }
}
int main() {

//   freopen("P1908_1.in", "r", stdin);
//   freopen("P1908_1.out", "w", stdout);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  merge(0, n - 1);
  cout << res;
  return 0;
}