#include <bits/stdc++.h>
#include <map>
#include <random>
#include <utility>
#include <vector>

using namespace std;
class RandomizedSet {
public:
  map<int, int> val_index;
  vector<int> nums;
  int end = 0;
  mt19937 rng;
  RandomizedSet() {
    random_device rd;
    rng.seed(rd());
    nums = vector<int>(2e5);
  }
  bool insert(int val) {
    if (!val_index.count(val)) {
      val_index.insert(pair<int, int>(val, end));
      nums[end] = val;
      end += 1;
      return true;
    } else {
      return false;
    }
    return false;
  }

  bool remove(int val) {
    if (val_index.count(val)) {
      int index = val_index.at(val);
      end -= 1;
      nums[index] = nums[end];
      if (end != 0) {
        auto it = val_index.find(nums[index]);
        it->second = index;
      }
      val_index.erase(val);
      return true;
    } else {
      return false;
    }
    return false;
  }

  int getRandom() {
    uniform_int_distribution<int> dist(0, end - 1);
    return nums[dist(rng)];
  }
};
int main() { return 0; }