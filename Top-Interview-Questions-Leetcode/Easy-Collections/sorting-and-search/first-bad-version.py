# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    def firstBadVersion(self, n: int) -> int:
        l = 1
        
        while l <= n:
            m = l + (n - l) // 2
            
            if isBadVersion(m):
                n = m - 1
            else:
                l = m + 1
        
        return l