class Solution:
    def reverse(self, x: int) -> int:
        sign = -1 if x < 0 else 1
        
        x = abs(x)
        
        reversed_x = 0
        
        INT_MAX = (1 << 31) - 1
        INT_MIN = - (1 << 31)

        while x > 0:
            digit = x % 10
            
            if reversed_x > INT_MAX // 10 or (reversed_x == INT_MAX // 10 and digit > 7):
                return 0
            
            reversed_x = reversed_x * 10 + digit
            x //= 10

        result = sign * reversed_x
        
        if result > INT_MAX or result < INT_MIN:
            return 0
        
        return result

# Example usage
def main():
    solution = Solution()
    test_cases = [123, -123, 120, 0, 1534236469]
    
    for x in test_cases:
        result = solution.reverse(x)
        print(f"Input: {x}, Reversed: {result}")

if __name__ == "__main__":
    main()