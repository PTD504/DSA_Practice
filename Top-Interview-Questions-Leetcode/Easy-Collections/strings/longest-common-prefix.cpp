#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        int n = strs.size();
        std::string longest_prefix = "";
        int maximum_size = INT_MAX;
        
        for (std::string str : strs) maximum_size = std::min(maximum_size, int(str.size()));
        
        for (int i = 0; i < maximum_size; ++i) {
            char ch = strs[0][i];
            bool check = 1;
            
            for (std::string str : strs) {
                if (str[i] != ch) {
                    check = 0;
                    break;
                }
            }
            
            if (check) longest_prefix += ch;
            else break;
        }
        
        return longest_prefix;
    }
    
    // Space optimized version
    std::string longestCommonPrefix_optimized(std::vector<std::string>& strs) {
        int n = strs.size();
        int len = strs[0].size();
        
        for (int i = 1; i < n; ++i) {
            len = std::min(len, (int)strs[i].size());
            
            int j = 0, cur = 0;
            
            while (j < len and strs[i][j] == strs[i - 1][j]) j++, cur++;
            
            len = cur;
        }
        
        return strs[0].substr(0, len);
    }
};

int main() {
    Solution solution;
    std::vector<std::string> strs = {"flower", "flow", "flight"};
    std::string result = solution.longestCommonPrefix(strs);
    std::cout << "Longest common prefix: " << result << std::endl; 
    return 0;
}   