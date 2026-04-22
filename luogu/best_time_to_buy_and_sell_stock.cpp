#include <bits/stdc++.h>
#include <vector>

using namespace std;
int maxProfit(vector<int> &prices) {
    vector<int> max_prices(prices.size());
    int cur_max = prices[prices.size() - 1], profit = 0;
    for(int i = prices.size() - 1; i >= 0; i--) {
        cur_max = max(prices[i], cur_max);
        max_prices[i] = cur_max;
    }
    for(int i = 0; i < prices.size(); i++) {
        if(prices[i] < max_prices[i]) {
            profit = max(max_prices[i] - prices[i], profit);
        }
    }
    return profit;
}

int main() { 
    vector<int> prices = {1,2};
    int p = maxProfit(prices);
    cout << p << endl;
    return 0; }