
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
private:
    
    ListNode* reverse_recursively(ListNode* head) {
        if (head->next == nullptr) return head;
        
        ListNode* reverse_sublist = reverse_recursively(head->next);
        
        head->next->next = head;
        
        head->next = nullptr;
        
        return reverse_sublist;
    }
    
    ListNode* reverse_iteratively(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* next = head;
        
        while (head) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        
        return prev;
    }
    
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return head;
        
        return reverse_recursively(head);
    }
};