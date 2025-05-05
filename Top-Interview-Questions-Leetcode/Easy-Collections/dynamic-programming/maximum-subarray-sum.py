from typing import List

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        mn, mx, sum = 0, nums[0], 0
        
        for num in nums:
            sum += num
            mx = max(mx, sum - mn)
            mn = min(mn, sum)
        
        return mx