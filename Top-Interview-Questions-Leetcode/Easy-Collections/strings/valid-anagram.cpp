#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        std::vector<int> cnt(26);
        
        for (char ch : s) cnt[ch - 'a']++;
        
        for (char ch : t) cnt[ch - 'a']--;
        
        for (int val : cnt) if (val) return false;
        
        return true;
    }
};

// Example usage
int main() {
    Solution solution;
    std::string s = "phanthanhdang";
    std::string t = "dangphanthanh";
    
    if (solution.isAnagram(s, t)) {
        std::cout << s << " and " << t << " are anagrams." << std::endl;
    } else {
        std::cout << s << " and " << t << " are not anagrams." << std::endl;
    }
    
    return 0;
}