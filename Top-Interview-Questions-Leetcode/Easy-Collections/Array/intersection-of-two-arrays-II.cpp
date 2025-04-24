#include <iostream>
#include <vector>
// #include <unordered_map>
#include "Path_to_your_file\UnorderedMap.h" // Assuming you have a custom header for unordered_map

// If the given arrays are not sorted
#define HASHMAP 
// #define ARRAYS_SORTED

class Solution {
public:
    std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        std::vector<int> intersect;
        
        #ifdef HASHMAP
        
        // std::unordered_map<int, int> mp;
        UnorderedMap<int, int> mp;
        
        for (int num : nums1) mp[num]++;
        
        for (int num : nums2) {
            if (mp[num] > 0) {
                intersect.push_back(num);
                mp[num]--;
                
            }
        }
        
        return intersect;
        
        #endif
        
        
        #ifdef ARRAYS_SORTED
        
        int i1 = 0, i2 = 0;
        
        while (i1 < n1 and i2 < n2) {
            if (nums1[i1] == nums2[i2]) {
                intersect.push_back(nums1[i1]);
                i1++, i2++;
            }
            else if (nums1[i1] < nums2[i2]) i1++;
            else i2++;
        }
        
        return intersect;
        
        #endif
    }
};

// Example usage
int main() {
    Solution solution;
    std::vector<int> nums1 = {1, 2, 4, 4, 5, 5, 5, 5, 6, 7, 8, 8, 8, 8, 9};
    std::vector<int> nums2 = {1, 4, 4, 5, 6, 6, 7, 8, 9, 9}; 
    
    std::vector<int> result = solution.intersect(nums1, nums2);
    
    for (int num : result) {
        std::cout << num << " "; 
    }
    
    return 0;
}