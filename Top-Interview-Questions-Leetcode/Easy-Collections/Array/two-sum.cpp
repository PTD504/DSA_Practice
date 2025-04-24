#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>

class Solution {
private:
    
    // I have implemented quick sort and binary search in "Sorting.h" and "Searching.h" respectively.
    // The below code is for summiting the solution to LeetCode. 
    template<typename T>
    void quick_sort(std::vector<T>& nums, int low, int high) {
        if (low >= high) return;
        
        int l = low, h = high;
        T mid = nums[l + (h - l) / 2];
        
        while (l < h) {
            while (nums[l] < mid) l++;
            while (nums[h] > mid) h--;
            
            if (l <= h) {
                swap(nums[l++], nums[h--]);
            }
        }
        
        if (l < high) quick_sort(nums, l, high);
        if (h > low) quick_sort(nums, low, h);
    }
    
    template<typename T>
    int binary_search(const std::vector<T>& nums, int target, int offset) {
        int low = offset, high = nums.size() - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (nums[mid].first == target) return mid;
            else if (nums[mid].first > target) high = mid - 1;
            else low = mid + 1;
        }
        
        return -1;
    }

protected:
    
    std::vector<int> twoSum_Onlogn_solution(std::vector<int>& nums, int target) {
        std::vector<std::pair<int, int> > p_nums;
        
        for (int i = 0; i < nums.size(); ++i) p_nums.push_back({nums[i], i});
        
        quick_sort(p_nums, 0, p_nums.size() - 1);
        
        for (int i = 0; i < nums.size() - 1; ++i) {
            
            int idx = binary_search(p_nums, target - p_nums[i].first, i + 1);
            
            if (idx != -1) {
                return {p_nums[i].second, p_nums[idx].second};
            }
        }
        
        return {};
    }
    
    std::vector<int> twoSum_On_solution(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> mp;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (mp.find(target - nums[i]) != mp.end()) {
                return {mp[target - nums[i]], i};
            }
            
            mp[nums[i]] = i;
        }
        
        return {};
    }
    
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        return twoSum_Onlogn_solution(nums, target);
        // return twoSum_On_solution(nums, target);
    }
};

// Example usage
int main() {
    Solution solution;
    std::vector<int> nums = {4, 7, 2, 15, 9, 3, 12, 8, 6, 11, 5, 13, 1, 14, 10, 16, 0, 17, 19, 18, 20};
    int target = 17;
    
    std::vector<int> result = solution.twoSum(nums, target);
    
    std::cout << "Indices: " << result[0] << ", " << result[1] << std::endl;
    
    return 0;
}