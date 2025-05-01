from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def __isValidBST(self, root: Optional[TreeNode], mn: int, mx: int) -> bool:
        if root == None:
            return True
        
        if root.val > mx or root.val < mn:
            return False
        
        return self.__isValidBST(root.left, mn, root.val - 1) & self.__isValidBST(root.right, root.val + 1, mx)
    
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        return self.__isValidBST(root, -(1 << 31) - 1, (1 << 31))