/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) */
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        
        int lpath = height(root->left, root->val), rpath = height(root->right, root->val);
        
        return max({lpath + rpath, longestUnivaluePath(root->left), longestUnivaluePath(root->right)});
    }
    
    int height(TreeNode *root, int data) {
        if(!root) return 0;
        
        if(root->val != data) return 0;
        
        return 1 + max(height(root->left, data), height(root->right, data));
        
    }
};