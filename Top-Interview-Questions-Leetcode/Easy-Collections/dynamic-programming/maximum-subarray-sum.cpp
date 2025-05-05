#include <iostream>
#include <vector>

class Solution {
private:
    
    int divide_and_conquer(std::vector<int>& nums, int low, int high) {
        // Update ...
    }
    
public:
    int maxSubArray(std::vector<int>& nums) {
        int mn = 0, mx = nums[0], sum = 0;
        
        for (int num : nums) {
            sum += num;
            mx = std::max(mx, sum - mn);
            mn = std::min(mn, sum);
        }
        
        return mx;
    }
};