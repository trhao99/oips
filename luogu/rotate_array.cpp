#include <algorithm>
#include <bits/stdc++.h>
#include <utility>
#include <vector>

using namespace std;

// void rotate(vector<int> &nums, int k) {
//     int tmp;
//     k = k % nums.size();
//     for(int i = 0; i < k; i++){
//         tmp = nums[0];
//         for(int j = nums.size() - 1; j >= 0; j--) {
//            nums[(j+1)%nums.size()] = nums[j];
//         }
//         nums[1%nums.size()] = tmp;

//     }
// }
void rotate(vector<int> &nums, int k) {
  k = k % nums.size();
  reverse(nums.begin(), nums.end());
  reverse(nums.begin(), nums.begin() + k);
  reverse(nums.begin() + k, nums.end());
}
int main() {
  vector<int> vec = {1, 2, 3, 4, 5, 6, 7};
  rotate(vec, 3);
  for (int val : vec)
    cout << val << " ";
  cout << endl;
  return 0;
}