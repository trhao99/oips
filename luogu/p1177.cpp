#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> vec(n);
  for(int i = 0; i < n; i++) cin >> vec[i];
  sort(vec.begin(), vec.end());
  for (auto v : vec) cout << v << " ";
  return 0;
}
