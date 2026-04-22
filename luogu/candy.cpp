#include <bits/stdc++.h>
#include <vector>

using namespace std;

int candy(vector<int> &ratings) {
  int res = 0, cur_num = 1, n = ratings.size(), min_c = 1;
  vector<int> cs(n);
  cs[0] = 1;
  for (int i = 1; i < n; i++) {
    if (ratings[i] > ratings[i - 1]) {
      cur_num++;
      cs[i] = cur_num;
    } else if (ratings[i] < ratings[i - 1]) {
      cur_num--;
      if (cur_num < min_c)
        min_c = cur_num;
      cs[i] = cur_num;
    } else {
      cs[i] = min_c;
    }
  }
  int add_num = min_c <= 0 ? (-min_c) + 1 : 0;
  for (int i = 0; i < n; i++) {
    res += (cs[i] + add_num);
  }
  return res;
}
// 2 3 2 2 1
// 1 2 1 2 1
int main() { 
    vector<int> ratingfs = {1,3,2,2,1};
    int res = candy(ratingfs);
    cout << res << endl;
    return 0;
}