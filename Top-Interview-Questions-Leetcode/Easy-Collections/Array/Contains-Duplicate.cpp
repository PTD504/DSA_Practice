#include <iostream>
#include <vector>

class Solution {

public:
    bool containsDuplicate(std::vector<int>& nums) {
        int n = nums.size();
        
        for (int i = 1; i < n; ++i) {
            int j = i;
            
            while (j >= 1) {
                if (nums[j - 1] == nums[j]) return true;
                else if (nums[j - 1] < nums[j]) 
                    break;
                else {
                    std::swap(nums[j - 1], nums[j]);
                }
                
                j--;
            }
        }
        
        return false;
        
    }
};

// Example usage
int main() {
    Solution solution;
    std::vector<int> nums = {2, 3, 1, 4, 5, 6, 1, 7, 3};
    
    if (solution.containsDuplicate(nums)) {
        std::cout << "Contains duplicate." << std::endl;
    } else {
        std::cout << "No duplicates found." << std::endl;
    }
    
    return 0;
}