# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSumOpt(self, head: Optional[ListNode]) -> int:
        slow, fast = head, head

        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
        
        prev, next = None, slow

        while slow:
            next = slow.next
            slow.next = prev
            prev = slow
            slow = next
        
        maxTwin = 0

        while prev:
            maxTwin = max(maxTwin, prev.val + head.val)
            prev = prev.next
            head = head.next
        
        return maxTwin

    def pairSum(self, head: Optional[ListNode]) -> int:

        # return self.pairSumOpt(head)

        linkedListValues = []

        while head:
            linkedListValues.append(head.val)
            head = head.next

        i, j = 0, len(linkedListValues) - 1
        maxTwin = 0

        while i < j:
            maxTwin = max(maxTwin, linkedListValues[i] + linkedListValues[j])
            i += 1
            j -= 1
        
        return maxTwin