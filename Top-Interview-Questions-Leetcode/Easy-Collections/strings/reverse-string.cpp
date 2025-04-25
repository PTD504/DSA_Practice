#include <iostream>
#include <vector>

class Solution {
public:
    void reverseString(std::vector<char>& s) {
        int l = 0, h = s.size() - 1;
        
        while (l < h) {
            std::swap(s[l++], s[h--]);
        }
    }
};

// Example usage
int main() {
    Solution solution;
    std::vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    
    solution.reverseString(s);
    
    for (char c : s) {
        std::cout << c << " ";
    }
    
    return 0;
}