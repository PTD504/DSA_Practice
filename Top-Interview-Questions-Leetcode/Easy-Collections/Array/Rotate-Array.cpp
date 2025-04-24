#include <iostream>
#include <vector>

// Change the define to test different implementations
#define ROTATE2

class Solution {
private:
    
    void swap(int& a, int& b) {
        a ^= b;
        b ^= a;
        a ^= b;
    }

    void reverse(std::vector<int>& nums, int l, int h) {
        while (l < h) {
            swap(nums[l++], nums[h--]);
        }
    }
    
public:
    void rotate(std::vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        
        if (k == 0) return;
        
        
        // O(n) space complexity
        #ifdef ROTATE
        
        int idx = n - k;
        vector<int> temp;
        
        for (; idx < n; ++idx) temp.push_back(nums[idx]);
        
        for (int i = 0; i < n - k; ++i) temp.push_back(nums[i]);
        
        for (int i = 0; i < n; ++i) nums[i] = temp[i];
        
        #endif
        
        
        // O(k) space complexity
        #ifdef ROTATE1
        
        int idx = n - k;
        vector<int> temp;
        
        for (; idx < n; ++idx) temp.push_back(nums[idx]);
        
        int h = n - 1, l = n - k - 1;
            
        while (l >= 0) {
            nums[h] = nums[l];
            h--, l--;
        }
        
        while (h >= 0) {
            nums[h] = temp.back();
            temp.pop_back();
            h--;
        }
            
        #endif
        
        
        // O(1) space complexity
        #ifdef ROTATE2
        
        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
        
        #endif
    }
};

// Example usage
int main() {
    Solution solution;
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    
    solution.rotate(nums, k);
    
    for (int num : nums) {
        std::cout << num << " ";
    }
    
    return 0;
}