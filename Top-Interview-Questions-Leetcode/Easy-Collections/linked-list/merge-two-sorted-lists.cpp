

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* merge_list = nullptr;
        ListNode* head = nullptr;
        
        while (list1 or list2) {
            if (list2 == nullptr) {
                if (merge_list) merge_list->next = list1, merge_list = merge_list->next;
                else merge_list = list1;
                list1 = list1->next;
            }
            else if (list1 == nullptr) {
                if (merge_list) merge_list->next = list2, merge_list = merge_list->next;
                else merge_list = list2;
                list2 = list2->next;
            }
            
            else if (list1->val < list2->val) {
                if (merge_list) merge_list->next = list1, merge_list = merge_list->next;
                else merge_list = list1;
                list1 = list1->next;
            }
            else {
                if (merge_list) merge_list->next = list2, merge_list = merge_list->next;
                else merge_list = list2;
                list2 = list2->next;
            }
            
            if (head == nullptr) head = merge_list;
        }
 
        return head;
    }
};