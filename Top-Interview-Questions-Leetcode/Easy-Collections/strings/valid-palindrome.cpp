#include <iostream>
#include <string>

class Solution {
public:
    bool isPalindrome(std::string s) {
        int l = 0, h = s.size() - 1;
        
        while (l < h) {
            if (!isalpha(s[l]) and !isdigit(s[l])) l++; // You can use isalnum() function to check both at once
            else if (!isalpha(s[h]) and !isdigit(s[h])) h--;
            else if (tolower(s[l]) != tolower(s[h])) return false;
            else l++, h--;
        }
        
        return true;
    }
};

// Example usage
int main() {
    Solution solution;
    std::string s = "I am the king ???? of the world! dlrow eht fo !!!! gnik eht ma I";

    bool result = solution.isPalindrome(s);
    std::cout << (result ? "true" : "false") << std::endl;
}