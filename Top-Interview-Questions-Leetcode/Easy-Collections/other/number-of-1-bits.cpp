class Solution {
private:
    
    int hammingWeight_recursion(int n) {
        if (n <= 1) return n;
        
        return (n & 1) + hammingWeight_recursion(n >> 1);
    }
    
public:
    int hammingWeight(int n) {
        int cnt = 0;
        
        while (n) {
            if (n & 1) cnt++;
            n >>= 1;
        }
        
        return cnt;
    }
};