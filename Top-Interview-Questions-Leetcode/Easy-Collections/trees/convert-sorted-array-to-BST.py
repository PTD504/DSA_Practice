from typing import List, Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def __sortedArrayToBST(self, nums: List[int], l: int, h: int) -> Optional[TreeNode]:
        if l > h:
            return None
        if l == h:
            node = TreeNode(nums[l])
            return node
        
        m = l + (h - l) // 2
        
        left = self.__sortedArrayToBST(nums, l, m - 1)
        node = TreeNode(nums[m])
        right = self.__sortedArrayToBST(nums, m + 1, h)
        
        node.left = left
        node.right = right
        
        return node
    
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        return self.__sortedArrayToBST(nums, 0, len(nums) - 1)