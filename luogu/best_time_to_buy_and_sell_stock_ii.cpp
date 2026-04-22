#include <bits/stdc++.h>
#include <vector>

using namespace std;
int maxProfit(vector<int> &prices) {
  int profit = 0;
  if (prices.size() == 1)
    return 0;
  for (int i = 0; i < prices.size() - 1; i++) {
    if (prices[i] < prices[i + 1])
      profit += (prices[i + 1] - prices[i]);
  }
  return profit;
}
int main() { return 0; }