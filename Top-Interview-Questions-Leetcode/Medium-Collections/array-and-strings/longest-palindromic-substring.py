class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        isPalin = [[False for _ in range(n)] for _ in range(n)]
        ans = 1
        
        for i in range(n):
            isPalin[i][i] = True
            
        for l in range(2, n + 1):
            for i in range(0, n - l + 1):
                j = i + l - 1
                if l == 2:
                    isPalin[i][j] = (s[i] == s[j])
                else:
                    isPalin[i][j] = (s[i] == s[j]) & isPalin[i + 1][j - 1]
                
                ans = max(ans, l) if isPalin[i][j] else ans
        
        for i in range(n):
            if isPalin[i][i + ans - 1]:
                return s[i:i + ans]