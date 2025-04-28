/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

// Uncomment the approach you want to use
#define OPTIMIZED
// #define REVERSE_APPROACH
// #define DIRECT_SOLUTION

class Solution {
private:
    
    ListNode* reverse(ListNode* node) {
        ListNode* prev = nullptr;
        ListNode* next = node;
        
        while (node) {
            next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }
        
        return prev;
    }
    
    ListNode* removeNthFromStart(ListNode* head, int n) {
        if (n == 1) return head->next;
        
        ListNode* cur = head;
        ListNode* prev = nullptr;
        
        while (--n) prev = cur, cur = cur->next;
        
        prev->next = cur->next;
        
        return head;
    }
    
    ListNode* removeNthFromEnd_optimized(ListNode* head, int n) {
        ListNode* node = new ListNode(0, head);
        
        ListNode* iter_tail = node;
        ListNode* iter_head = node;
        
        // int n_temp = n;
        
        while (n--) {
            iter_tail = iter_tail->next;
        }
        
        if (iter_tail->next) {
            while (iter_tail->next) iter_tail = iter_tail->next, iter_head = iter_head->next;

            iter_head->next = iter_head->next->next;
            
            return head;
        }
        else {
            iter_head->next = iter_head->next->next;
            
            return iter_head->next;
        }
    }
    
public:
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        #ifdef REVERSE_APPROACH
        head = reverse(head);
        
        head = removeNthFromStart(head, n);
        
        return reverse(head);
        #endif
        
        #ifdef DIRECT_SOLUTION
        int sz = 0;
        
        ListNode * cur = head;
        
        while (cur) sz++, cur = cur->next;
        
        n = sz - n + 1;
        
        return removeNthFromStart(head, n);
        #endif
        
        #ifdef OPTIMIZED
        return removeNthFromEnd_optimized(head, n);
        #endif
    }
};