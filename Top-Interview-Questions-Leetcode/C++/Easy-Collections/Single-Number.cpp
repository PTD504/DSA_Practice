#include <iostream>
#include <vector>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        // 0 ^ x = x
        // x ^ x = 0
        // x ^ y ^ z ^ x ^ z = y ^ (x ^ x) ^ (z ^ z) = y ^ 0 ^ 0 = y
        // So we can use XOR to find the single number in the array
        // where all other numbers appear twice.
        int num = 0;
        
        for (int val : nums) num ^= val;
        
        return num;
    }
};

// Example usage
int main() {
    Solution solution;
    std::vector<int> nums = {4, 1, 2, 1, 2};
    int result = solution.singleNumber(nums);
    std::cout << "The single number is: " << result << std::endl; // Output: 4
    return 0;
}