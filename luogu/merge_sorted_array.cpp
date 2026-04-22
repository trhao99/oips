#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
  vector<int> res(m+n);
  int index_1= 0, index_2=0, res_index = 0;
  while(index_1 < m && index_2 < n){
    if(nums1[index_1] <= nums2[index_2]) res[res_index++] = nums1[index_1++];
    else res[res_index++] = nums2[index_2++];
  }
  while(index_1 < m) res[res_index++] = nums1[index_1++];
  while(index_2 < n) res[res_index++] = nums2[index_2++];
  nums1 = res;
}
int main() {
  vector<int> nums1 = {1, 2, 3, 0, 0, 0};
  vector<int> nums2 = {2, 5, 6};

  // vector<int> nums1 = {0};
  // vector<int> nums2 = {1};

  // vector<int> nums1 = {1};
  // vector<int> nums2 = {};
  merge(nums1, 3, nums2, 3);
  for (int val : nums1) {
    cout << val << " ";
  }
  cout << endl;
  return 0;
}
