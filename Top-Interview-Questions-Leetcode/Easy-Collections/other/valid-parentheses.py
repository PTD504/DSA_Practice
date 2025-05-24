class Solution:
    def isValid(self, s: str) -> bool:
        prefix = []
        
        for ch in s:
            if ch == '(' or ch == '[' or ch == '{':
                prefix.append(ch)
            elif not prefix:
                return False
            elif abs(ord(prefix[-1]) - ord(ch)) > 2:
                return False
            else:
                prefix.pop()
        
        return not prefix