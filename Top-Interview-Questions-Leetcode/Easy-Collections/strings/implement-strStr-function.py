class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        # return haystack.find(needle)
        lh, ln = len(haystack), len(needle)
        
        for i in range(lh - ln + 1):
            if haystack[i: i + ln] == needle: 
                return i
        
        return -1

# Example usage
def main():
    haystack = "dangphanthanh"
    needle = "hanh"
    solution = Solution()
    result = solution.strStr(haystack, needle)
    print(result) 

if __name__ == "__main__":
    main()