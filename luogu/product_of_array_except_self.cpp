#include <bits/stdc++.h>

using namespace std;
vector<int> productExceptSelf(vector<int> &nums) {
  int n = nums.size();
  vector<int> front(n);
  vector<int> back(n);
  vector<int> res(n);
  int front_num = 1, back_num = 1;
  for (int i = 0; i < n; i++) {
    front_num *= nums[i];
    back_num *= nums[n - (i + 1)];
    if (i + 1 < n)
      front[i + 1] = front_num;
    if (n - (i + 2) >= 0)
      back[n - (i + 2)] = back_num;
  }
  res[0] = back[0];
  res[n - 1] = front[n - 1];
  for (int i = 1; i < n - 1; i++) {
    res[i] = front[i] * back[i];
  }
  return res;
}

int main() { return 0; }