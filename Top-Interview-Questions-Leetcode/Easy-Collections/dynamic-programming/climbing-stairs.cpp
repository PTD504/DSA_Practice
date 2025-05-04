class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        else if (n == 2) return 2;
        
        int ways;
        
        for (int i = 3, f = 1, s = 2; i <= n; ++i) {
            ways = f + s;
            f = s;
            s = ways;
        }
        
        return ways;
    }
};