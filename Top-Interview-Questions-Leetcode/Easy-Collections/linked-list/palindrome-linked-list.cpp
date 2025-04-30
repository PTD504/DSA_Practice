#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {

private:
    
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        
        while (head) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;            
        }
        
        return prev;
    }
    
    bool isPalindrome_bruteforce(ListNode* head) {
        std::vector<int> vals;
        
        while (head) vals.push_back(head->val), head = head->next;
        
        int l = 0, h = vals.size() - 1;
        
        while (l < h) if (vals[l++] != vals[h--]) return false;
        
        return true;
    }
    
private:
    
    bool isPalindrome_space_optimized(ListNode* head) {
        ListNode* node = head;
        int sz = 0;
        
        while (node) sz++, node = node->next;
        
        if (sz == 1) return true;
        
        int sublist = (sz >> 1);
        ListNode* next = nullptr;
        node = nullptr; // prev
        
        while (sublist--) {
            next = head->next;
            head->next = node;
            node = head;
            head = next;
        }
        
        if (sz & 1) {
            next = next->next;
        }
        
        while (node) {
            if (node->val != next->val) return false;
            node = node->next, next = next->next;
        }
        
        return true;
    }

private:
    
    ListNode* find_middle_point(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    bool isPalindrome_operations_optimized(ListNode* head) {
        ListNode* mid = find_middle_point(head);
        
        if (mid == head) return true;
        
        // Reverse the second part of the list (begin with the node mid)
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        
        while (mid) {
            next = mid->next;
            mid->next = prev;
            prev = mid;
            mid = next;
        }
        
        // Check palindrome
        while (prev) {
            if (head->val != prev->val) return false;
            
            head = head->next;
            prev = prev->next;
        }
        
        return true;
    }
    
public:
    bool isPalindrome(ListNode* head) {
        return isPalindrome_operations_optimized(head);
    }
};