from typing import Optional 

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def __reverse_iteratively(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev = None
        next = None
        
        while head != None:
            next = head.next
            head.next = prev
            prev = head
            head = next
        
        return prev
    
    def __reverse_recursively(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head.next == None:
            return head
        
        reverse_sublist = self.__reverse_recursively(head.next)
        
        head.next.next = head
        head.next = None
        
        return reverse_sublist
            
    
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head == None:
            return head
        
        return self.__reverse_recursively(head)
        