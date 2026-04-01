# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        if root == None:
            return 0
        traceSum = defaultdict(int)
        traceSum[0] = 1

        def dfs(root, currentSum):
            paths = 0
            currentSum += root.val
            paths += traceSum[currentSum - targetSum]
            traceSum[currentSum] += 1
            
            if root.left:
                paths += dfs(root.left, currentSum)
            if root.right:
                paths += dfs(root.right, currentSum)
            
            traceSum[currentSum] -= 1
            
            return paths
        
        return dfs(root, 0)
