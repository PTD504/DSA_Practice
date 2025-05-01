#include <iostream>
#include <stack>
#include <climits>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    
    bool isValidBST(TreeNode* root, int mn, int mx) {
        if (root->val < mn or root->val > mx) return false;
        
        bool valid = true;
        
        if (root->left) {
            if (root->val == INT_MIN) return false;
            
            valid = isValidBST(root->left, mn, root->val - 1);
        }
        
        if (root->right) {
            if (root->val == INT_MAX) return false;
            
            valid &= isValidBST(root->right, root->val + 1, mx);
        }
        
        return valid;
    }
    
    bool isValidBST_iteratively(TreeNode* root) {
        std::stack<TreeNode*> st;
        long cur_min = -(1ll << 31) - 1;
        
        while (root or !st.empty()) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            
            root = st.top();
            st.pop();
            
            if ((long)root->val <= cur_min) return false;
            else cur_min = root->val;
            
            root = root->right;
        }
        
        return true;
    }
    
public:
    bool isValidBST(TreeNode* root) {
        // return isValidBST(root,INT_MIN, INT_MAX);
        return isValidBST_iteratively(root);
    }
};