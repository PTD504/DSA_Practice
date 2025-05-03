from typing import List

class Solution:
    
    def __reverse(self, nums: List[int], l: int, h: int):
        while l < h:
            nums[l] ^= nums[h]
            nums[h] ^= nums[l]
            nums[l] ^= nums[h]
            
            l += 1
            h -= 1
    
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        self.__reverse(nums1, 0, m - 1)
        
        i, i1, i2 = m + n - 1, m - 1, 0
        
        while i1 >= 0 and i2 < n:
            if nums1[i1] < nums2[i2]:
                nums1[i] = nums1[i1]
                i1  -= 1
            else:
                nums1[i] = nums2[i2]
                i2 += 1
            i -= 1
        
        while i2 < n:
            nums1[i] = nums2[i2]
            i -= 1
            i2 += 1
        
        self.__reverse(nums1, 0, m + n - 1)
        