from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        mp = {}
        
        for i, val in enumerate(nums):
            if target - nums[i] in mp:
                return [mp[target - nums[i]], i]
            
            mp[nums[i]] = i
        
        return []
        
# Example usage
if __name__ == "__main__":
    solution = Solution()
    nums = [2, 7, 11, 15]
    target = 9
    result = solution.twoSum(nums, target)
    print(result)  # Output: [0, 1]