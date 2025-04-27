#include <iostream>
#include <string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        // if (haystack == needle) return 0;
        
        int nh = haystack.size(), nn = needle.size();
        
        for (int i = 0; i <= nh - nn; ++i) {
            int j = 0, i_temp = i;
            
            while (j < nn and haystack[i_temp] == needle[j]) i_temp++, j++;
            
            if (j >= nn) return i;
        }
        
        return -1;
    }
};

// Example usage
int main() {
    Solution solution;
    std::string haystack = "phanthanhdang", needle = "hanh";
    int result = solution.strStr(haystack, needle);
    std::cout << "The index of the first occurrence of needle in haystack is: " << result << std::endl;
    return 0;
}