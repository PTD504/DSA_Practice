
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
    
private:
    
    bool hasCycle_updated(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        
        while (fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (fast == slow) return true;
        }
        
        return false;
    }
    
public:
    bool hasCycle(ListNode *head) {
        return hasCycle_updated(head);
        
        int MAX_VAL = 1e5;
        
        while (head) {
            if (head->val > MAX_VAL) return true;
            head->val = MAX_VAL + 1;
            head = head->next;
        }
        
        return false;
    }
};