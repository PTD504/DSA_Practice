from typing import List

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        n, length = len(strs), len(strs[0])
        
        for i in range(1, n):
            length = min(length, len(strs[i]))
            j, cur_length = 0, 0
            
            while j < length and strs[i][j] == strs[i - 1][j]:
                j += 1
                cur_length += 1
            
            length = cur_length
        
        return strs[0][:length]

def main():
    # Example usage
    solution = Solution()
    strs = ["flower", "flow", "flight"]
    result = solution.longestCommonPrefix(strs)
    print(result)  

if __name__ == "__main__":
    main()