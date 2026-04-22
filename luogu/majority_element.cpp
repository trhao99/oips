#include <bits/stdc++.h>
#include <vector>

using namespace std;

int majorityElement(vector<int> &nums) {
  if (nums.size() == 1)
    return nums[0];
  int cur = nums[0], num = 1;
  for (int i = 1; i < nums.size(); i++) {
    if(num == 0) {
        cur = nums[i];
        num = 1;
    }else {
        if(nums[i] == cur) {
            num++;
        }else {
            num--;
        }
    }
  }
  return cur;
}
int main() { 
    // vector<int> vec = {3,2,3};
    vector<int> vec = {2,2,1,1,1,2,2};
    int res = majorityElement(vec);
    cout << res << endl;
    return 0; }