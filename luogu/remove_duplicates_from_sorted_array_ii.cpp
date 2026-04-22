#include <bits/stdc++.h>
#include <vector>

using namespace std;
int removeDuplicates(vector<int> &nums) {
    if(nums.size() == 1 || nums.size() == 2) return nums.size(); 
    int index = 1, last_num = nums[0], cur_num_num = 1;
    while(index < nums.size()) {
        if(nums[index] == last_num) cur_num_num++;
        else {
            last_num = nums[index];
            cur_num_num = 1;
        }
        if(cur_num_num > 2) {
            nums.erase(nums.begin() + index);
        }else {
            index++;
        }
    }
    return nums.size();
}
int main() { 
    // vector<int> vec = {1,1,1,2,2,3};
    vector<int> vec = {0,0,1,1,1,1,2,3,3};
    int res = removeDuplicates(vec);
    for(int val : vec) {
        cout << val << " ";
    }
    cout << endl;
    cout << "res: " << res << endl;
    return 0; }