class Solution:
    def isPowerOfThree_recursion(self, n: int):
        if n <= 0:
            return False
        if n == 1:
            return True
        
        if n % 3 != 0:
            return False
        
        return self.isPowerOfThree_recursion(n // 3)
    
    def isPowerOfThree_binarySearch(self, n: int):
        if n <= 0:
            return False
        
        l, h = 0, 19
        
        while l <= h:
            m = l + (h - l) // 2
            val = pow(3, m) - n
            
            if val == 0:
                return True
            elif val > 0:
                h = m - 1
            else:
                l = m + 1
        
        return False
    
    def isPowerOfThree(self, n: int) -> bool:
        if n <= 0:
            return False
        
        return 1162261467 % n == 0