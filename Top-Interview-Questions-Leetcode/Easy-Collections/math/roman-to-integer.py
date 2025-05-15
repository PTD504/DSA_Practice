class Solution:
    def romanToInt(self, s: str) -> int:
        mp = {
            ' ': 0,
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000
        }
        
        prev, cur, sum = 0, 0, 0
        
        for ch in s:
            cur = mp[ch]
            
            if prev > cur:
                sum += prev
                prev = cur
            elif prev == cur:
                prev += cur
            else:
                prev = cur - prev
        
        return sum + prev