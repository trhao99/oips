#include <bits/stdc++.h>
#include <vector>

using namespace std;

int jump(vector<int> &nums) {
    if(nums.size() == 1 || nums.size() == 2) return nums.size() - 1;
    vector<int> jump_steps(nums.size(), nums.size());
    jump_steps[0] = 0;
    for(int i = 0; i < nums.size(); i++) {
        if(jump_steps[i] == nums.size()) continue;
        for(int j = 1; j <= nums[i]; j++) {
            if(i + j >= jump_steps.size()) break;
            else jump_steps[i+j] = min(jump_steps[i+j], jump_steps[i] +1);
        }
    }
    return jump_steps.back();
}
int main() { return 0; }