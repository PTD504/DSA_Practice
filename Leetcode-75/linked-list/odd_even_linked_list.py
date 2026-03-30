# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head == None or head.next == None:
            return head
        
        oddNode = head
        evenNode = head.next
        # oddHeadNode - The head node of odd linked list - is exactly head
        evenHeadNode = evenNode

        while evenNode and evenNode.next:
            oddNode.next = evenNode.next
            oddNode = oddNode.next
            evenNode.next = oddNode.next
            evenNode = evenNode.next
        
        oddNode.next = evenHeadNode

        return head
