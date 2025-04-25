#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    int firstUniqChar(std::string s) {
        std::vector<int> freq(26);
        
        for (char ch : s) freq[ch - 'a']++;
        
        for (int i = 0; i < s.size(); ++i) {
            if (freq[s[i] - 'a'] == 1) return i;
        }
        
        return -1;
    }
};

// Example usage
int main() {
    Solution solution;
    std::string s = "phanthanhdang";
    int result = solution.firstUniqChar(s);
    std::cout << "The index of the first unique character is: " << result << std::endl;
    return 0;
}