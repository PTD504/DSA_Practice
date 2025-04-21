#include <iostream>
#include <vector>

class Solution {
        
public:
    int removeDuplicates(std::vector<int>& nums) {
        int cnt = 1, n = nums.size();
        int curIdx = 1, curVal = nums[0];
        
        for (int i = 1; i < n; ++i) {
            if (nums[i] == curVal) {
                nums[i] = -1;
            }
            else {
                curVal = nums[i];
                nums[curIdx++] = nums[i];
                if (curIdx < i) nums[i] = -1;
                cnt++;
                
                while (curIdx < i and nums[curIdx] != -1) curIdx++;
            }
        }
        
        return cnt;
    }
};

// Example usage
int main() {
    Solution solution;
    std::vector<int> nums = {1, 1, 2, 3, 3, 4};
    int newLength = solution.removeDuplicates(nums);
    
    std::cout << "New length: " << newLength << std::endl;
    std::cout << "Modified array: ";
    for (int i = 0; i < newLength; ++i) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}