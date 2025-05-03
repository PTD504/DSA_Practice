#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        
        std::reverse(nums1.begin(), nums1.begin() + m);
        
        int i1 = m - 1, i2 = 0, i = m + n - 1;
        
        while (i1 >= 0 and i2 < n) {
            if (nums1[i1] < nums2[i2]) {
                nums1[i--] = nums1[i1--];
            }
            else {
                nums1[i--] = nums2[i2++];
            }
        }
        
        while (i2 < n) nums1[i--] = nums2[i2++];
        
        reverse(nums1.begin(), nums1.end());
    }
};
    