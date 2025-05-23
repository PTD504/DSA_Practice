from typing import List
import random

class Solution:

    def __init__(self, nums: List[int]):
        self.origin = nums[:]

    def reset(self) -> List[int]:
        return self.origin

    def shuffle(self) -> List[int]:
        nums = self.origin[:]
        
        for i in range(len(nums) - 1, -1, -1):
            idx = random.randint(0, i)
            nums[idx], nums[i] = nums[i], nums[idx]
            
        return nums


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()