from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def __find_middle_point(self, head: Optional[ListNode]) -> bool:
        fast = slow = head
        
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
        
        return slow
    
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        mid = self.__find_middle_point(head)
        
        if mid == head:
            return True
        
        prev, next = None, None
        
        while mid:
            next = mid.next
            mid.next = prev
            prev = mid
            mid = next
        
        while prev:
            if prev.val != head.val:
                return False
            
            prev = prev.next
            head = head.next
        
        return True