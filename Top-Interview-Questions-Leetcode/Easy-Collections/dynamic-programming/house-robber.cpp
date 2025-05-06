#include <iostream>
#include <vector>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> dp(n);
        dp[0] = nums[0];
        
        for (int i = 1; i < n; ++i) {
            dp[i] = nums[i];
            
            if (i > 1) dp[i] += dp[i - 2];
            
            dp[i] = std::max(dp[i], dp[i - 1]);
        }
        
        return dp[n - 1];
    }
};