#include <bits/stdc++.h>
#include <cmath>
#include <vector>

using namespace std;

int removeElement(vector<int> &nums, int val) {
  int eq_index = 0, neq_index = nums.size() - 1, k = 0;
  for(int i = 0; i < nums.size(); i++){
    if(nums[i] != val) k++;
  }
  if(k == 0 || k == nums.size()) return k;
  while (eq_index < neq_index) {
    while (nums[eq_index] != val){
      eq_index++;
    }
    while (nums[neq_index] == val) {
      neq_index--;
    }
    if (eq_index >= neq_index) {
      break;
    }
    nums[eq_index] = nums[neq_index];
    nums[neq_index] = val;
  }
  return k;
}
int main() {
  vector<int> vec = {0, 1, 2, 2, 3, 0, 4, 2};
//   vector<int> vec = {3,2,2,3};
  int k = removeElement(vec, 2);
  for (int val : vec) {
    cout << val << " ";
  }
  cout << endl;
  cout << "k: " << k << endl;
  return 0;
}