from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        merge_list = None
        head = None
        
        while list1 != None and list2 != None:
            if list1.val < list2.val:
                if merge_list != None:
                    merge_list.next = list1
                    merge_list = merge_list.next
                else:
                    merge_list = list1
                
                list1 = list1.next
            else:
                if merge_list != None:
                    merge_list.next = list2
                    merge_list = merge_list.next
                else:
                    merge_list = list2
                
                list2 = list2.next
            
            if head == None:
                head = merge_list
        
        while list1 != None:
            if merge_list != None:
                merge_list.next = list1
                merge_list = merge_list.next
            else:
                merge_list = list1
                head = merge_list
            
            list1 = list1.next
        
        while list2 != None:
            if merge_list != None:
                merge_list.next = list2
                merge_list = merge_list.next
            else:
                merge_list = list2
                head = merge_list
            
            list2 = list2.next
        
        return head