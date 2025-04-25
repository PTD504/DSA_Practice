from typing import List

class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        
        l, h = 0, len(s) - 1
        
        while l < h:
            temp = s[l]
            s[l] = s[h]
            s[h] = temp
            
            l += 1
            h -= 1

# Example usage
def main():
    s = ["h", "e", "l", "l", "o"]
    solution = Solution()
    solution.reverseString(s)
    print(s)

if __name__ == "__main__":
    main()