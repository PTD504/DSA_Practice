#include <iostream>
#include <vector>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int n = s.size(), i = 0, j = 0, ans = 0;
        std::vector<int> a(95);
        
        while (j < n) {
            a[s[j] - ' ']++;
            
            while (a[s[j] - ' '] > 1) {
                a[s[i++] - ' ']--;
            }
            
            ans = std::max(ans, j - i + 1);
            
            j++;
        }
        
        return ans;
    }
};