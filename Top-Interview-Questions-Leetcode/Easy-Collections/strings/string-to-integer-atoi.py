class Solution:
    def myAtoi(self, s: str) -> int:
        i, n, sign = 0, len(s), 1
        
        while i < n and s[i] == ' ':
            i += 1
        
        if i < n and s[i] == '-':
            sign = -1
            i += 1
        elif i < n and s[i] == '+':
            i += 1
        
        INT_MAX, INT_MIN = (1 << 31) - 1, -(1 << 31)
        num = 0
        
        while i < n and s[i].isdigit():
            num = 10 * num + (ord(s[i]) - ord('0'))
            i += 1
            
            if num * sign > INT_MAX:
                return INT_MAX
            if num * sign < INT_MIN:
                return INT_MIN
        
        return sign * num

# Example usage
def main():
    solution = Solution()
    print(solution.myAtoi("   -42"))  # Output: -42
    print(solution.myAtoi("4193 with words"))  # Output: 4193
    print(solution.myAtoi("words and 987"))  # Output: 0
    print(solution.myAtoi("-91283472332"))  # Output: -2147483648 (INT_MIN)

if __name__ == "__main__":
    main()