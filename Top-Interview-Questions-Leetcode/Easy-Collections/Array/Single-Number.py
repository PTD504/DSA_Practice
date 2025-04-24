from typing import List

class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        num = 0
        
        for val in nums:
            num ^= val
        
        return num

# Example usage
def main():
    nums = [4, 1, 2, 1, 2]
    solution = Solution()
    result = solution.singleNumber(nums)
    print(f"The single number is: {result}")

if __name__ == "__main__":
    main()