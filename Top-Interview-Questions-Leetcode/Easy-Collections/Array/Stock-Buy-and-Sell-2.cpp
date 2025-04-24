#include <iostream>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int max_profit = 0, n = prices.size();
        
        for (int i = 1; i < n; ++i) {
            if (prices[i] > prices[i - 1]) max_profit += prices[i] - prices[i - 1];
        }
        
        return max_profit;
    }
};

// Example usage
int main() {
    Solution solution;
    std::vector<int> prices = {7, 1, 5, 3, 6, 4};
    int result = solution.maxProfit(prices);
    std::cout << "Maximum profit: " << result << std::endl; // Output: 7
    return 0;
}