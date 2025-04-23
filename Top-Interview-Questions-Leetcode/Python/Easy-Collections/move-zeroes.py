from typing import List

class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        
        j = 0
        
        for i in range(0, len(nums)):
            if nums[i] == 0:
                continue
            
            temp = nums[i]
            nums[i] = nums[j]
            nums[j] = temp
            j += 1

# Example usage
def main():
    nums = [0, 1, 0, 3, 12]
    print(f"Input: {nums}")
    Solution().moveZeroes(nums)
    print(f"Output: {nums}")

if __name__ == "__main__":
    main()