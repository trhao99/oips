#include <bits/stdc++.h>
#include <vector>

using namespace std;

bool canJump(vector<int> &nums) {
  vector<bool> reachable(nums.size());
  reachable[0] = true;
  if (nums.size() == 1)
    return true;
  for (int i = 0; i < nums.size() - 1; i++) {
    if (nums[i] == 0 || !reachable[i])
      continue;
    for (int j = 0; j <= nums[i]; j++) {
      if (i + j >= nums.size())
        break;
      else
        reachable[i + j] = true;
    }
  }
  return reachable[reachable.size() - 1];
}
int main() {
  vector<int> nums = {3, 2, 1, 0, 4};
  canJump(nums);
  return 0;
}