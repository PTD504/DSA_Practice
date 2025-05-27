from typing import List

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        n = len(nums)
        ans = []
        
        for i in range(0, n - 2):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            
            l, h = i + 1, n - 1
            
            while l < h:
                s = nums[i] + nums[l] + nums[h]
                
                if s == 0:
                    res = [nums[i], nums[l], nums[h]]
                    ans.append(res)
                    
                    l += 1
                    h -= 1
                    
                    while l < h and nums[l] == nums[l - 1]: 
                        l += 1
                    while h > l and nums[h] == nums[h + 1]:
                        h -= 1
                elif s > 0:
                    h -= 1
                else:
                    l += 1
        
        return ans
        