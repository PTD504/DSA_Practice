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
    int max(int a, int b) {
        return a > b ? a : b;
    }
    
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        
        return max(left, right) + 1;
    }
};