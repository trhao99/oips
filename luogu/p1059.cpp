#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 1;
int arr[N] = {0};
int main() {
  int n, num, res = 0;
  bool first = true;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> num;
    arr[num]++;
    if(arr[num] == 1) res++;
  }
  cout << res << endl;
  for (int i = 1; i < N; i++) {
    if (arr[i]) {
      if (first) {
        cout << i;
        first = false;
      } else {
        cout << " " << i;
      }
    }
  }
  return 0;
}