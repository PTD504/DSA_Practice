class Solution:
    def firstUniqChar(self, s: str) -> int:
        freq = [0 for _ in range(26)]
        
        for i in range(len(s)):
            char = ord(s[i]) - ord('a')
            freq[char] += 1
        
        for i in range(len(s)):
            char = ord(s[i]) - ord('a')
            
            if freq[char] == 1:
                return i
        
        return -1

# Example usage
def main():
    s = "phanthanhdang"
    solution = Solution()
    result = solution.firstUniqChar(s)
    print(result)

if __name__ == "__main__":
    main()