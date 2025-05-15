class Solution:
    def __hammingWeight_recursion(self, n: int) -> int:
        if n <= 1:
            return n
        
        return (n & 1) + self.__hammingWeight_recursion(n >> 1)
    
    def hammingWeight(self, n: int) -> int:
        cnt = 0
        
        while n > 0:
            cnt += (n % 2)
            n >>= 1
        
        return cnt