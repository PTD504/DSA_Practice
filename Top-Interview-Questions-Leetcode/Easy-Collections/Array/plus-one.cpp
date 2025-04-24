#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        int n = digits.size();
        int r = 0;
        
        digits[n - 1] += 1;
        
        for (int i = n - 1; i > 0; --i) {
            digits[i] += r;
            
            if (digits[i] > 9) {
                digits[i] %= 10;
                r = 1;
            }
            else r = 0;
        }
        
        digits[0] += r;
        
        if (digits[0] > 9) {
            digits[0] %= 10;
            digits.insert(digits.begin(), 1, 1);
        }
        
        return digits;
    }
};

// Example usage
int main() {
    Solution solution;
    std::vector<int> digits = {9, 9, 9, 9, 9, 9};
    
    for (int digit : digits) {
        std::cout << digit;
    }

    std::cout << " + 1 = ";

    std::vector<int> result = solution.plusOne(digits);

    for (int digit : result) {
        std::cout << digit;
    }
    
    return 0;
}