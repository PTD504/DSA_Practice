from queue import Queue
from typing import List, Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []
        
        ans = []
        queue = Queue()
        queue.put(root)
        
        while not queue.empty():
            sz = queue.qsize()
            vals = []
            
            for _ in range(sz):
                node = queue.get()
                
                vals.append(node.val)
                
                if node.left:
                    queue.put(node.left)
                if node.right:
                    queue.put(node.right)
            
            ans.append(vals)
        
        return ans