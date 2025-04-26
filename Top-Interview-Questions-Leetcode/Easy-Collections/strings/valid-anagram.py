class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        cnt = [0 for _ in range(26)]
        
        for ch in s:
            cnt[ord(ch) - ord('a')] += 1
        
        for ch in t:
            cnt[ord(ch) - ord('a')] -= 1
            
        for val in cnt:
            if val != 0:
                return False
        
        return True

# Example usage
def main():
    s = "dangphanthanh"
    t = "thanhdangphan"
    solution = Solution()
    result = solution.isAnagram(s, t)
    print(f"Is '{s}' an anagram of '{t}'? {result}")

if __name__ == "__main__":
    main()