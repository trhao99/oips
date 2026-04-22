#include <bits/stdc++.h>
#include <vector>

using namespace std;
int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
  int n = gas.size();
  vector<int> diff(n);
  int min_nums = gas[0] - cost[0], min_index = 0, diff_num = 0;
  for (int i = 0; i < n; i++) {
    diff[i] = gas[i] - cost[i];
    diff_num += diff[i];
    if (diff_num < min_nums) {
      min_nums = diff_num;
      min_index = i;
    }
  }
  int res = 0;
  for (int i = (min_index + 1) % n; i < n; i++) {
    res += diff[i];
    if (res < 0)
      return -1;
  }
  for (int i = 0; i <= min_index; i++) {
    res += diff[i];
    if (res < 0)
      return -1;
  }
  return (min_index + 1) % n;
}
int main() {
  vector<int> gas = {3, 1, 1};
  vector<int> cost = {1, 2, 2};
  int res = canCompleteCircuit(gas, cost);
  cout << res << endl;
  return 0;
}