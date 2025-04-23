#include <iostream>
#include <vector>

class Solution {
public:
    
    // Original solution
    void moveZeroes(std::vector<int>& nums) {
        int n = nums.size();
        int non_zero_idx = 0, zero_idx = 0;
        
        while (non_zero_idx < n and nums[non_zero_idx] == 0) non_zero_idx++;
        while (zero_idx < n and nums[zero_idx] != 0) zero_idx++;
        
        if (non_zero_idx >= n or zero_idx >= n) return;
        
        while (non_zero_idx < n) {
            if (non_zero_idx >= zero_idx) {
                std::swap(nums[non_zero_idx], nums[zero_idx]);
                zero_idx++;
            }
            else {
                non_zero_idx++;
            }
            
            while (non_zero_idx < n and nums[non_zero_idx] == 0) non_zero_idx++;
            while (zero_idx < n and nums[zero_idx] != 0) zero_idx++;
        }
    }
    
    // Operations optimized solution
    void moveZeroes_operations_optimized(std::vector<int>& nums) {
        for (int i = 0, j = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) continue;
            std::swap(nums[i], nums[j]);
            j++;
        }
    }
};

// Example usage
int main() {
    Solution solution;
    std::vector<int> nums = {0, 1, 0, 3, 12, 0, 1, 2, 3, -1, 2, 0, 0, 1};
    
    // Using the original solution
    solution.moveZeroes(nums);
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    // Resetting the vector for the optimized solution
    nums = {0, 1, 0, 3, 12, 0, 1, 2, 3, -1, 2, 0, 0, 1};
    
    // Using the operations optimized solution
    solution.moveZeroes_operations_optimized(nums);
    for (int num : nums) {
        std::cout << num << " ";
    }
    
    return 0;
}