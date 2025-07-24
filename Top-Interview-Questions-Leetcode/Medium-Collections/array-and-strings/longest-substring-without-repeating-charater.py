class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        n, i, j, ans = len(s), 0, 0, 0
        a = [0 for _ in range(95)]
        
        while j < n:
            char = ord(s[j]) - ord(' ')
            
            a[char] += 1
            
            while a[char] > 1:
                a[ord(s[i]) - ord(' ')] -= 1
                i += 1
            
            ans = max(ans, j - i + 1)
            j += 1
        
        return ans