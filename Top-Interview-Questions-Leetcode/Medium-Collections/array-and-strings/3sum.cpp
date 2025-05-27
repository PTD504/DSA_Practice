#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
private:
    
    bool is_vector_equal(std::vector<int>& arr1, std::vector<int>& arr2) {
        return arr1[0] == arr2[0] and arr1[1] == arr2[1] and arr1[2] == arr2[2];
    }
    
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        std::vector<std::vector<int> > ans;
        
        for (int i = 0, l = 1, h = n - 1, sum; i < n - 2; ++i, l = i + 1, h = n - 1) {
            if (i > 0 and nums[i] == nums[i - 1]) continue;
            
            while (l < h) {
                sum = nums[l] + nums[h] + nums[i];
                if (sum == 0) {
                    std::vector<int> res = {nums[i], nums[l], nums[h]};
                    
                    if (ans.size() == 0 or !is_vector_equal(ans.back(), res)) {
                        ans.push_back(res);
                    }
                    
                    l++, h--;
                }
                else if (sum > 0) h--;
                else l++;
            }
        }
        
        return ans;
    }
};