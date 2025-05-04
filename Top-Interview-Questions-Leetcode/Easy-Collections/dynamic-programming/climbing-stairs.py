class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 1:
            return 1
        if n == 2:
            return 2
        
        f, s, ways = 1, 2, 0
        
        for _ in range(3, n + 1):
            ways = f + s
            f, s = s, ways
        
        return ways