#include <iostream>
#include <vector>
#include <string>

// Use this if you want to use the optimized version
// #define OPTIMIZED

class Solution {
private:
    
    int compare_string(const std::string& num1, const std::string& num2) {        
        if (num1.size() != num2.size()) {
            return num1.size() > num2.size() ? 1 : -1;
        }
        
        if (num1 == num2) return 0;
        
        return num1 > num2 ? 1 : -1;
    }
    
    void reverse(std::string& str) {
        int l = 0, h = str.size() - 1;
        
        while (l < h) {
            std::swap(str[l++], str[h--]);
        }
    }
    
public:
    int reverse(int x) {
        
        #ifdef OPTIMIZED
        return reverse_optimized(x);
        #endif
        
        std::string sx = std::to_string(x);
        
        if (x < 0) sx = sx.substr(1);
        
        reverse(sx);
        
        std::string inf = std::to_string((1 << 31)), sup = std::to_string(-((1 << 31) + 1));
        
        inf = inf.substr(1);
        
        if (compare_string(sx, inf) > 0 or compare_string(sx, sup) > 0) return 0;
        
        if (x > 0) {
            return stoi(sx);
        }
        else return - stoi(sx);
    }
    
    int reverse_optimized(int x) {
        int reverse_x = 0;
        
        while (x != 0) {
            int digit = x % 10;
            
            if (INT_MAX / 10 < reverse_x or (INT_MAX / 10 == reverse_x and digit > 7)) return 0;
            if (INT_MIN / 10 > reverse_x or (INT_MIN / 10 == reverse_x and digit < -8)) return 0;
            
            reverse_x = 10 * reverse_x + digit;
            x /= 10;
        }
        
        return reverse_x;
    }
};

int main() {
    Solution solution;
    
    std::cout << solution.reverse(123) << '\n'; 
    std::cout << solution.reverse(-123) << '\n'; 
    std::cout << solution.reverse(120) << '\n'; 
    std::cout << solution.reverse(0) << '\n'; 
    std::cout << solution.reverse(1534236469) << '\n';
    
    return 0;
}