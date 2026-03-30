# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteMiddleOpt(self, head: Optional[ListNode]) -> Optional[ListNode]:
        fast, slow = head, head
        prevSlow = None
        
        while fast and fast.next:
            fast = fast.next.next
            prevSlow = slow
            slow = slow.next
        
        prevSlow.next = slow.next

        return head

    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head.next == None:
            return None
        
        return self.deleteMiddleOpt(head)
        
        travelHead = head
        numNodes = 0

        while travelHead != None:
            numNodes += 1
            travelHead = travelHead.next
        
        numNodes //= 2
        travelHead = head
        prevNode = None

        while numNodes:
            prevNode = travelHead
            travelHead = travelHead.next
            numNodes -= 1
        
        prevNode.next = travelHead.next

        return head