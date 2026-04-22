#include <bits/stdc++.h>
#include <vector>

using namespace std;
int removeDuplicates(vector<int> &nums) {
  int res = 0;
  vector<int> nums_map(201);
  for (int i = 0; i < nums.size(); i++) {
    nums_map[nums[i] + 100]++;
  }
  int index = 0;
  for (int i = 0; i < nums_map.size(); i++) {
    if (nums_map[i] != 0) {
      res++;
      nums[index++] = i - 100;
    }
  }
  return res;
}
int main() {
  vector<int> vec = {1, 1, 2};
  int res = removeDuplicates(vec);
  for (int val : vec) {
    cout << val << " ";
  }
  cout << endl;
  cout << "res: " << res << endl;
  return 0;
}