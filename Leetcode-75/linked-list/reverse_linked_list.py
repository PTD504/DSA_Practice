# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseListRecursively(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head.next == None:
            return head
        
        subListHead = self.reverseListRecursively(head.next)
        head.next.next = head
        head.next = None

        return subListHead
    
    def reverseListIteratively(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev = None
        next = head

        while head:
            next = head.next
            head.next = prev
            prev = head
            head = next
        
        return prev
    
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head == None:
            return head

        # return self.reverseListRecursively(head)
        return self.reverseListIteratively(head)