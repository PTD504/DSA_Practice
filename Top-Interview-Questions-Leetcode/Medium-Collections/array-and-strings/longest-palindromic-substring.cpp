#include <iostream>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        int n = s.size(), l = 0, h = 0;
        
        for (int i = 0, left, right; i < n - 1; ++i) {
            left = i, right = i + 1;
            while (left >= 0 and right < n and s[left] == s[right]) {
                if (right - left + 1 > h - l + 1) l = left, h = right;
                left--, right++;
            }
            
            left = i - 1, right = i + 1;
            while (left >= 0 and right < n and s[left] == s[right]) {
                if (right - left + 1 > h - l + 1) l = left, h = right;
                left--, right++;
            }
            
        }
        
        return s.substr(l, h - l + 1);
    }
};