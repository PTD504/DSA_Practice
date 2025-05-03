#include <iostream>
#include <vector>

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
    
    TreeNode* sortedArrayToBST(std::vector<int>& nums, int l, int h) {
        if (l > h) return nullptr;
        
        if (l == h) {
            TreeNode* node = new TreeNode(nums[l]);
            return node;
        }
        
        int mid = l + (h - l) / 2;
        
        TreeNode* left = sortedArrayToBST(nums, l, mid - 1);
        TreeNode* node = new TreeNode(nums[mid]);
        TreeNode* right = sortedArrayToBST(nums, mid + 1, h);
        
        node->left = left;
        node->right = right;
        
        return node;
    }
    
public:
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }
};