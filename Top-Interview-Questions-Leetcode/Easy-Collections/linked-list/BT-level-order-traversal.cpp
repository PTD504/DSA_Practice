#include <iostream>
#include <vector>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        
        std::vector<std::vector<int> > ans;
        std::queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int sz = q.size();
            std::vector<int> vals;
            
            while (sz--) {
                TreeNode* node = q.front();
                q.pop();
                
                vals.push_back(node->val);
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            ans.push_back(vals);
        }
        
        return ans;
    }
};