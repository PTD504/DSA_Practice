#include <cmath>

class Solution {
public:
    
    bool isPowerOfThree_recursion(int n) {
        if (n <= 0) return false;
        if (n == 1) return true;
        if (n % 3 != 0) return false;
        
        return isPowerOfThree_recursion(n / 3);
    }
    
    bool isPowerOfThree_binarySearch(int n) {
        int l = 0, h = 19; // 3 ^ 20 > INT_MAX = 2^31 - 1
        
        while (l <= h) {
            int m = l + (h - l) / 2;
            int val = int(pow(3, m));
            
            if (n == val) return true;
            else if (n < val) h = m - 1;
            else l = m + 1;
        }
        
        return false;
    }
    
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        
        return 1162261467 % n == 0;
    }
};