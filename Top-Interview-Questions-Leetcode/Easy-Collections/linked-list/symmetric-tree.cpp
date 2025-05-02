#include <iostream>
#include <queue>
#include <utility>

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
    
    bool isSymmetric_recursively(TreeNode* left, TreeNode* right) {
        if (!left and !right) return true;
        if (left or right) return false;
        if (left->val != right->val) return false;
        
        return isSymmetric_recursively(left->left, right->right) & isSymmetric_recursively(left->right, right->left);
    }
    
    bool isSymmetric_iteratively(TreeNode* root) {
        std::queue<std::pair<TreeNode*, TreeNode*> > q;
        q.push({root->left, root->right});
        
        while (!q.empty()) {
            auto [left, right] = q.front();
            q.pop();
            
            if (!left and !right) continue;
            else if (!left or !right) return false;
            else if (left->val != right->val) return false;
            else {
                q.push({left->left, right->right});
                q.push({left->right, right->left});
            }
        }
        
        return true;
    }
    
public:
    bool isSymmetric(TreeNode* root) {
        // return isSymmetric_recursively(root->left, root->right);
        return isSymmetric_iteratively(root);
    }
};