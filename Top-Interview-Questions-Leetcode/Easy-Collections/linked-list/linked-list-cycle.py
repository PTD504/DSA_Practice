from typing import Optional

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        fast = head
        
        while fast and fast.next:
            fast = fast.next.next
            head = head.next
            
            if fast == head:
                return True
        
        return False