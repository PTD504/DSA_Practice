from typing import List

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        n, r = len(digits), 0
        
        digits[-1] += 1
        
        for i in range(n - 1, 0, -1):
            digits[i] += r
            r = 0
            
            if digits[i] > 9:
                digits[i] %= 10
                r = 1
        
        digits[0] += r
        
        if digits[0] > 9:
            digits[0] %= 10
            digits.insert(0, 1)
        
        return digits

# Example usage
def main():
    digits = [9, 9, 9]
    print(f"{''.join(map(str, digits))} + 1 = ", end="")
    solution = Solution()
    result = solution.plusOne(digits)
    print(f"{''.join(map(str, result))}")

if __name__ == "__main__":
    main()