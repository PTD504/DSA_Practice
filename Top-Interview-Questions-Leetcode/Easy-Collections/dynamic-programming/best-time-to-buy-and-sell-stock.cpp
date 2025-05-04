#include <iostream>
#include <vector>
#include <climits>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        
        int mx_profit = 0, mn_price = INT_MAX;
        
        for (int i : prices) {
            mx_profit = std::max(mx_profit, i - mn_price);
            mn_price = std::min(mn_price, i);
        }
        
        return mx_profit;
    }
};