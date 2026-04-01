# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def _goodNodes(self, root: TreeNode, curMaxVal: int):
        goodNodes = 0

        if root.val >= curMaxVal:
            goodNodes += 1
        
        curMaxVal = max(curMaxVal, root.val)
        
        if root.left:
            goodNodes += self._goodNodes(root.left, curMaxVal)
        if root.right:
            goodNodes += self._goodNodes(root.right, curMaxVal)
        
        return goodNodes

    def goodNodes(self, root: TreeNode) -> int:
        return self._goodNodes(root, int(-1e4 - 1))