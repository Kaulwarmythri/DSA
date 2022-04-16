/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        
        TreeNode *left = root->left, *right = root->right;
        root->left = NULL;
        
        flatten(left);
        flatten(right);
        
        root->right = left;
        TreeNode *curr = root;
        while(curr->right) curr = curr->right;
        curr->right = right;
    }
};