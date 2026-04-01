# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def longestZigZag(self, root: Optional[TreeNode]) -> int:
        if root.left == None and root.right == None:
            return 0

        maxZigzagPath = 0

        def dfs(root: Optional[TreeNode], child: str = "left"):
            nonlocal maxZigzagPath
            if root == None:
                return 0
            if root.left == None and root.right == None:
                return 1
            
            leftZigzagPath = dfs(root.left, "left") + 1
            rightZigzagPath = dfs(root.right, "right") + 1

            maxZigzagPath = max([maxZigzagPath, leftZigzagPath, rightZigzagPath])
            
            return leftZigzagPath if child == "right" else rightZigzagPath

        dfs(root, "left")

        return maxZigzagPath - 1