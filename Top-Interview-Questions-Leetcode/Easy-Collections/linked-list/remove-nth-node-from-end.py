from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def __removeNthFromStart(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        if n == 1:
            return head.next
        
        prev = None
        cur = head
        
        while n > 1:
            prev = cur
            cur = cur.next
            n -= 1
        
        prev.next = cur.next
        
        return head
    
    def __removeNthFromEnd_optimized(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        node = ListNode(0, head)
        fast = slow = node

        while n > 0:
            fast = fast.next
            n -= 1
        
        if not fast.next:
            slow.next = slow.next.next

            return slow.next
        else:
            while fast.next:
                fast = fast.next
                slow = slow.next
            
            slow.next = slow.next.next

            return head
    
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        sz = 0
        cur = head
        
        while cur:
            sz += 1
            cur = cur.next
        
        n = sz - n + 1
        
        return self.__removeNthFromStart(head, n)