#include <iostream>
#include <string>

// Use this macro to enable optimized operations
// #define __OPTIMIZE__ 

class Solution {
public:
    
    int myAtoi(std::string s) {
        
        #ifdef __OPTIMIZE__
        return myAtoi_optimized_operations(s);
        #endif
        
        int idx = 0, n = s.size();
        
        while (idx < n and s[idx] == ' ') idx++;
        
        if (idx >= n) return 0;
        
        bool neg = 0;
        long long num = 0;
        
        if (s[idx] == '-') {
            neg = 1;
            
            while (++idx < n) {
                if (!isdigit(s[idx])) break;
                num = 10 * num + (s[idx] - '0');
                
                if (num > INT_MAX) return INT_MIN;
            }
            
            return num * (-1);
        }
        else if (s[idx] == '+') {
            while (++idx < n) {
                if (!isdigit(s[idx])) break;
                num = 10 * num + (s[idx] - '0');
                
                if (num > INT_MAX) return INT_MAX;
            }
            
            return num;
        }
        else if (isdigit(s[idx])) {
            num += s[idx] - '0';
            
            while (++idx < n) {
                if (!isdigit(s[idx])) break;
                num = 10 * num + (s[idx] - '0');
                
                if (num > INT_MAX) return INT_MAX;
            } 
            
            return num;
        }
        else return 0;
    }
    
    int myAtoi_optimized_operations(std::string s) {
        int i = 0, n = s.size(), sign = 1;
        
        while (i < n and s[i] == ' ') i++;
        
        if (i < n and s[i] == '-') sign = -1, i++;
        else if (i < n and s[i] == '+') sign = 1, i++;
        
        long long num = 0;
        
        while (i < n and isdigit(s[i])) {
            num = 10 * num + (s[i++] - '0');
            
            if (sign * num > INT_MAX) return INT_MAX;
            if (sign * num < INT_MIN) return INT_MIN;
        }
        
        return sign * num;
    }
};

int main() {
    Solution solution;
    std::string str = "   -42234kj234h";
    int result = solution.myAtoi(str);
    std::cout << "The converted integer is: " << result << std::endl;
    return 0;
}