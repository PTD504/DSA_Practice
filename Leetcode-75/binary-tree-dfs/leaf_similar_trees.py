# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def _isLeafNode(self, root: Optional[TreeNode]) -> bool:
        return root.left == None and root.right == None
    
    def _dfs(self, root: Optional[TreeNode], leafNodeValues: list[int]):
        if self._isLeafNode(root):
            leafNodeValues.append(root.val)
            return
        
        if root.left:
            self._dfs(root.left, leafNodeValues)
        if root.right:
            self._dfs(root.right, leafNodeValues)

    def leafSimilar(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        leafNodeValues1 = []
        self._dfs(root1, leafNodeValues1)

        leafNodeValues2 = []
        self._dfs(root2, leafNodeValues2)

        return leafNodeValues1 == leafNodeValues2