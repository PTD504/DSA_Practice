from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def __isSymmetric_recursively(self, node1: Optional[TreeNode], node2: Optional[TreeNode]) -> bool:
        if not node1 and not node2:
            return True
        elif not node1 or not node2:
            return False
        elif node1.val != node2.val:
            return False
        else:
            return self.__isSymmetric_recursively(node1.left, node2.right) & self.__isSymmetric_recursively(node1.right, node2.left)
    
    def __isSymmetric_iteratively(self, root: Optional[TreeNode]) -> bool:
        nodes = [[root.left, root.right]]
        
        while nodes:
            left, right = nodes[-1]
            nodes.pop()
            
            if not left and not right:
                continue
            elif not left or not right:
                return False
            elif left.val != right.val:
                return False
            else:
                nodes.append([left.left, right.right])
                nodes.append([left.right, right.left])
        
        return True
    
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        # return self.__isSymmetric_recursively(root.left, root.right)
        return self.__isSymmetric_iteratively(root)
        